/* 
 * File:   main.cpp
 * Author: Zosia Sobocinska
 *
 * Created on November 13, 2013, 5:11 PM
 */

#include <iostream>

#include "headers/msgr/server.h"
#include "headers/msgr/subscriber.h"

using namespace std;

/**
 */
int main(int argc, char** argv) {

    Msgr::run_server(9002);

    return 0;
}

