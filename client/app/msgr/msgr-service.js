'use strict'

Application.Services.factory('msgrSrvc', ["$q", "$rootScope", function($q, $rootScope) {

        var socket = false;

        var apply = function(fun) {
            if (!$rootScope.$$digest) {
                $rootScope.$apply(fun);
            }
        };

        var callbacks = {};

        var register = function(purpose, callback) {
            if (!callbacks[purpose]) {
                callbacks[purpose] = [];
            }
            callbacks[purpose].push(callback);
        };
        var configure = function() {
            socket.onopen = function() {
                apply(function() {
                    state.connected = true;
                });
                log();
            };
            socket.onclose = function() {
                apply(function() {
                    state.connected = false;
                });
                log();
            };
            socket.onmessage = function(data) {
                console.log(data);
                var purpose = "";
                var message = "";
                console.error("OnMessage not implemented");
                var callback = callbacks[purpose];
                for (var i in callbacks) {
                    callbacks[i](message);
                }
            };
        };
        var log = function() {
            var label = "msgrService: "
            if (!(socket && socket instanceof WebSocket)) {
                console.log(label + "No socket");
            } else {
                var state;
                switch (socket.readyState) {
                    case 0:
                        state = "connecting";
                        break;
                    case 1:
                        state = "open";
                        break;
                    case 2:
                        state = "closing";
                        break;
                    case 3:
                        state = "closed";
                        break;
                }
                console.log(label + "Socket " + state)
            }
        };
        var connect = function(url) {
            if (socket instanceof WebSocket && socket.URL !== url) {
                disconnect();
                socket = false;
            }
            if (!socket || socket.readyState === 3) {
                socket = new WebSocket(url);
                configure();
            }
            log();
        };
        var send = function(msg) {
            if (state.connected) {
                socket.send(msg);
            }
        };
        var disconnect = function() {
            socket.close();
            socket = false;
        };
        var state = {
            connected: false
        };
        return {
            connect: connect,
            send: send,
            disconnect: disconnect,
            state: state,
        };
    }]);