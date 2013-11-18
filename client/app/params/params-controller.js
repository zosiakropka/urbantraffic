'use strict';

var paramsCtrl = function($scope, paramsSrvc) {

    $scope.submit_params = function() {
        return paramsSrvc.submit_params($scope.busIntervals);
    };
    $scope.busIntervals = {
        horizontal: 40,
        vertical: 40
    };
    $scope.intifyRange = function() {
        $scope.busIntervals.horizontal = parseInt($scope.busIntervals.horizontal);
        $scope.busIntervals.vertical = parseInt($scope.busIntervals.vertical);
    }
};
Application.Controllers.controller('paramsCtrl',
        ['$scope', 'paramsSrvc', paramsCtrl]);