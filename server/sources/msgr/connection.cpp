/* 
 * File:   sources/msgr/connection.cpp
 * Author: Zosia Sobocinska
 * 
 * Created on November 16, 2013, 5:56 PM
 */

#include "../../headers/msgr/connection.h"
#include "../../headers/msgr/server.h"

MsgrConn::MsgrConn() {
    //    hdl = NULL;
    //    id = -1;
}

MsgrConn::MsgrConn(int i, websocketpp::connection_hdl h) {
    id = i;
    hdl = h;
}

int MsgrConn::getId() {
    return id;
}

void MsgrConn::on_message(string message) {
    cout << "Message: " << message << endl;
    
    send(message);
}

void MsgrConn::send(string message) {
    Msgr::send(hdl, message);
}