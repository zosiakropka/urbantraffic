/* 
 * File:   message.h
 * Author: Zosia Sobocinska
 *
 * Created on November 17, 2013, 8:23 PM
 */

#ifndef MSGRMSG_H
#define MSGRMSG_H
#include <libjson/libjson.h>
#include <iostream>
#include <string>
using namespace std;

class MsgrMsg {
public:
    MsgrMsg(string json);
    string getPurpose();
    JSONNode getContent();
private:
    string purpose;
    JSONNode content;
};

#endif	/* MESSAGE_H */

