#include "MsgServiceBluetooth.h"


MsgServiceBluetooth::MsgServiceBluetooth(int rxPin, int txPin) {
    this->channel = new SoftwareSerial(rxPin, txPin);
}

void MsgServiceBluetooth::init() {
    channel->begin(9600);
    content.reserve(50);
    content = "";
    currentMsg = NULL;
    availableMsg = false;
}

bool MsgServiceBluetooth::isMsgAvailable() {
    while (channel->available()) {
        char ch = (char) channel->read();
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

Msg* MsgServiceBluetooth::receiveMsg() {
    if (availableMsg) {
        Msg* msg = currentMsg;
        availableMsg = false;
        currentMsg = NULL;
        content = "";
        return msg;
    }
    return NULL;
}

void MsgServiceBluetooth::sendMsg(Msg msg) {
    //channel->println(msg.getcontent());
}