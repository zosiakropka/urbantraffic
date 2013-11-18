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
            console.debug("msgrSrvc: " + purpose + " purpose registered.");
            if (!callbacks[purpose]) {
                callbacks[purpose] = [];
            }
            callbacks[purpose].push(callback);
        };
        var logConnection = function() {
            var label = "msgrService: ";
            if (!(socket && socket instanceof WebSocket)) {
                console.debug(label + "No socket");
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
                console.debug(label + "Socket " + state)
            }
        };
        var configure = function() {
            socket.onopen = function() {
                apply(function() {
                    state.connected = true;
                });
                logConnection();
            };
            socket.onclose = function() {
                apply(function() {
                    state.connected = false;
                });
                logConnection();
            };
            socket.onmessage = function(response) {
                var data = JSON.parse(response.data);
                console.debug(data);
                var purpose = data.purpose;
                delete data.purpose;
                if (callbacks[purpose]) {
                    var callback = callbacks[purpose];
                    for (var i in callback) {
                        callback[i](data);
                    }
                }
            };
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
            logConnection();
        };
        var send = function(purpose, content) {
            var data = {
                purpose: purpose,
                content: content,
            };
            var json = JSON.stringify(data);
            if (state.connected) {
                socket.send(json);
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
            register: register,
            connect: connect,
            send: send,
            disconnect: disconnect,
            state: state,
        };
    }]);