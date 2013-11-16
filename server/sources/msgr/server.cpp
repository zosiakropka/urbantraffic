/* 
 * File:   sources/msgr/server.cpp
 * Author: Zosia Sobocinska
 * 
 * Created on November 16, 2013, 12:40 PM
 */

#include <websocketpp/endpoint.hpp>


#include "../../headers/msgr/server.h"
#include "../../headers/msgr/connection.h"

unsigned int Msgr::port = 0;
Msgr::WSServer Msgr::server;
Msgr::Conns Msgr::conns;

void Msgr::run_server(unsigned int p) {
    if (!Msgr::port) {
        Msgr::port = p;

        Msgr::server.set_open_handler(on_open);
        Msgr::server.set_message_handler(on_message);

        Msgr::server.init_asio();
        Msgr::server.listen(Msgr::Msgr::port);
        Msgr::server.start_accept();

        Msgr::server.run();
    }
}

void Msgr::stop_server() {
    Msgr::server.stop();
    Msgr::port = 0;
}

void Msgr::on_open(websocketpp::connection_hdl hdl) {
    int conn_id = conns.size();
    MsgrConn conn(conn_id, hdl);

    Msgr::conns[hdl] = conn;
    cout << "Connection " << conn.getId() << endl;
}

void Msgr::on_message(websocketpp::connection_hdl hdl, WSServer::message_ptr msg) {
    string message = msg.get()->get_payload();
    Msgr::conns[hdl].on_message(message);
}

void Msgr::send(websocketpp::connection_hdl hdl, string msg) {
//    WSServer::message_ptr msg_ptr;
//    const char* msg_char = msg.c_str();
//    msg_ptr.get()->get_payload().append(msg_char);
    Msgr::server.send(hdl, msg, websocketpp::frame::opcode::TEXT);
}
