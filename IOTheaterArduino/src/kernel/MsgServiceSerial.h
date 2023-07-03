#ifndef __MSGSERVICESERIAL__
#define __MSGSERVICESERIAL__

#include "Msg.h"
#include "MsgService.h"

class MsgServiceSerial : public MsgService {
private:
    Msg* currentMsg;
    bool availableMsg;
    String content;

public:

    void init();

    bool isMsgAvailable();

    Msg* receiveMsg();

    void sendMsg(Msg msg);
};

#endif