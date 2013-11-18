/* 
 * File:   subscriber.h
 * Author: Zosia Sobocinska
 *
 * Created on November 17, 2013, 10:24 PM
 */

#ifndef SUBSCRIBER_H
#define	SUBSCRIBER_H

#include <iostream>
#include <string>

#include "connection.h"
using namespace std;

class MsgrSubscriber {
public:
    MsgrSubscriber();
    void setConnection(MsgrConn conn);
    void send(string message);
    virtual void on_message(string message);
private:
    MsgrConn connection;
};

#endif	/* SUBSCRIBER_H */

