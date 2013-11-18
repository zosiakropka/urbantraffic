'use strict';

Application.Services.factory('paramsSrvc', ["$rootScope", "msgrSrvc", function($rootScope, msgrSrvc) {

        var submit_params = function(busIntervals) {
            var params = {
                bus_intervals: busIntervals
            };
            msgrSrvc.send("params", params);
        };
        return {
            submit_params: submit_params
        };
    }]);
