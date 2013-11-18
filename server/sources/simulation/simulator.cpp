/* 
 * File:   Simulator.cpp
 * Author: Zosia Sobocinska
 * 
 * Created on November 18, 2013, 1:45 AM
 */

#include "../../headers/simulation/simulator.h"
#include "../../headers/msgr/message.h"

SimulationMngr::SimulationMngr() {
}

void SimulationMngr::on_message(string message) {
    try {
        MsgrMsg* msg = new MsgrMsg(message);
        cout << "Purpose: " << msg->getPurpose() << endl;
        send(message); // resent just for test; @todo: remove this
    } catch (string err) {
        cout << "In received message: " << err;
    }
}
