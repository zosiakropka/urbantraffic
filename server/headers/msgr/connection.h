/* 
 * File:   headers/msgr/connection.h
 * Author: Zosia Sobocinska
 *
 * Created on November 16, 2013, 5:56 PM
 */

#ifndef MSGRCONN_H
#define	MSGRCONN_H

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <iostream>
#include <string>
#include "message.h"
using namespace std;

class MsgrSubscriber;

class MsgrConn {
public:
    MsgrConn(int id, websocketpp::connection_hdl hdl, MsgrSubscriber* subscriber);
    MsgrConn();
    int getId();
    void on_message(string message);
    void send(string message);

private:
    int id;
    websocketpp::connection_hdl hdl;
    MsgrSubscriber* subsrciber;
};

#endif	/* MSGRCONN_H */

