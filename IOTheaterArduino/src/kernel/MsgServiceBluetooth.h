#ifndef __MSGSERVICEBLUETOOTH__
#define __MSGSERVICEBLUETOOTH__

#include <Arduino.h>
#include "MsgServiceBluetooth.h"
#include "Msg.h"
#include "MsgService.h"
#include "SoftwareSerial.h"


class MsgServiceBluetooth : public MsgService {
private:
    SoftwareSerial* channel;
    Msg* currentMsg;
    bool availableMsg;
    String content;
 

public:

    MsgServiceBluetooth(int rxPin, int txPin);

    void init();

    bool isMsgAvailable();

    Msg* receiveMsg();

    void sendMsg(Msg msg);
};

#endif