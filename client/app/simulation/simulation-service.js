'use strict';

Application.Services.factory('simulationSrvc', ["$rootScope", "msgrSrvc", function($rootScope, msgrSrvc) {

        var onmsge_position = function() {
            console.error("msgrSrvc: onmsge_position not implemented yet");
        };
        msgrSrvc.register("position", onmsge_position);

        var state = {
            running: false
        };
        return {
            state: state
        };
    }]);