/* 
 * File:   subscriber.cpp
 * Author: Zosia Sobocinska
 * 
 * Created on November 17, 2013, 10:24 PM
 */

#include "../../headers/msgr/subscriber.h"

void MsgrSubscriber::setConnection(MsgrConn conn) {
    connection = conn;
}
MsgrSubscriber::MsgrSubscriber() {}

void MsgrSubscriber::send(string message) {
    connection.send(message);
}
void MsgrSubscriber::on_message(string message) {}