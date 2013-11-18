/* 
 * File:   message.cpp
 * Author: Zosia Sobocinska
 * 
 * Created on November 17, 2013, 8:23 PM
 */

#include "../../headers/msgr/message.h"

MsgrMsg::MsgrMsg(string json) {
    JSONNode n = libjson::parse(json);
    if (n == JSON_NULL) {
        throw "Faulty JSON string as constructor param!";
    }
    content = JSON_NULL;
    JSONNode::const_iterator i = n.begin();
    while (i != n.end()) {
        std::string node_name = i -> name();

        if (node_name == "purpose" && i -> type() == JSON_STRING) {
            purpose = i->as_string();
        } else if (node_name == "content") {
            content = i->as_node();
        }

        ++i; //increment the iterator
    }
}

string MsgrMsg::getPurpose() {
    return purpose;
}
JSONNode MsgrMsg::getContent() {
    return content;
}
