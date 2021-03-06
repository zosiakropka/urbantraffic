'use strict';

var msgrCtrl = function($rootScope, $scope, msgrSrvc) {
    $scope.connect = function(conn_url) {
        msgrSrvc.connect(conn_url);
    };
    $scope.send = function(msg) {
        msgrSrvc.send(msg);
    };
    $scope.disconnect = function() {
        msgrSrvc.disconnect();
    };
    $scope.state = msgrSrvc.state;
};
Application.Controllers.controller('msgrCtrl',
        ['$rootScope', '$scope', 'msgrSrvc', msgrCtrl]);
