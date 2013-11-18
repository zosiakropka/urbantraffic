/* 
 * File:   sources/msgr/connection.cpp
 * Author: Zosia Sobocinska
 * 
 * Created on November 16, 2013, 5:56 PM
 */

#include "../../headers/msgr/connection.h"
#include "../../headers/msgr/server.h"
#include "../../headers/msgr/subscriber.h"

MsgrConn::MsgrConn() {
    id = -1;
}

MsgrConn::MsgrConn(int i, websocketpp::connection_hdl h, MsgrSubscriber* s) {
    id = i;
    hdl = h;
    subsrciber = s;
}

int MsgrConn::getId() {
    return id;
}

void MsgrConn::on_message(string message) {
    subsrciber->on_message(message);
}

void MsgrConn::send(string message) {
    Msgr::send(hdl, message);
}
