'use strict';

var elemsCtrl = function($rootScope, $scope, msgrSrvc, simulationSrvc) {
    $scope.connectionState = msgrSrvc.state;
    $scope.simulationState = simulationSrvc.state;
};
Application.Controllers.controller('elemsCtrl',
        ['$rootScope', '$scope', 'msgrSrvc', 'simulationSrvc', elemsCtrl]);
