/* 
 * File:   headers/msgr/server.h
 * Author: Zosia Sobocinska
 *
 * Created on November 16, 2013, 12:40 PM
 */

#ifndef MSGR_H
#define MSGR_H

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <iostream>
#include <map>
#include "connection.h"

using namespace std;

class Msgr {
public:
    static void run_server(unsigned int port = 9002);
    static void stop_server();
    static void send(websocketpp::connection_hdl hdl, string message);

private:

    typedef websocketpp::server<websocketpp::config::asio> WSServer;
    typedef map<websocketpp::connection_hdl, MsgrConn> Conns;

    Msgr();
    static WSServer server;
    static unsigned int port;
    static void on_message(websocketpp::connection_hdl hdl, WSServer::message_ptr msg);
    static void on_open(websocketpp::connection_hdl hdl);


    static Conns conns;
};

#endif  /* MSGR_H */
