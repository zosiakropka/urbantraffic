'use strict';

var paramsCtrl = function($scope, paramsSrvc) {
    $scope.move = function() {
        console.log("moved");
    };
};
Application.Controllers.controller('paramsCtrl',
        ['$scope', 'paramsSrvc', paramsCtrl]);