#include <Arduino.h>
#include "MsgServiceSerial.h"


void MsgServiceSerial::init() {
    Serial.begin(9600);
    while (!Serial) {};
    content.reserve(50);
    content = "";
    currentMsg = NULL;
    availableMsg = false;
}

bool MsgServiceSerial::isMsgAvailable() {
    while (Serial.available()) {
        char ch = (char) Serial.read();
        if (ch == '\n') {
            currentMsg = new Msg(content);
            availableMsg = true;
            return true;
        } else {
            content += ch;
        }
    }
    return false;
}

Msg* MsgServiceSerial::receiveMsg() {
    if (availableMsg) {
        Msg* msg = currentMsg;
        availableMsg = false;
        currentMsg = NULL;
        content = "";
        return msg;
    }
    return NULL;
}

void MsgServiceSerial::sendMsg(Msg msg) {
    Serial.println(msg.getcontent());
}