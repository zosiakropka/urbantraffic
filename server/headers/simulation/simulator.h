/* 
 * File:   Simulator.h
 * Author: Zosia Sobocinska
 *
 * Created on November 18, 2013, 1:45 AM
 */

#ifndef SIMULATIONMNGR_H
#define	SIMULATIONMNGR_H
#include <string>
#include "../../headers/msgr/subscriber.h"

class SimulationMngr: public MsgrSubscriber {
public:
    SimulationMngr();
    void on_message(string message);
private:
    
};

#endif	/* SIMULATIONMNGR_H */

