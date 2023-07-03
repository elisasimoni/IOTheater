#ifndef __MSGSERVICE__
#define __MSGSERVICE__

#include "Msg.h"



class MsgService {
public:
  
    virtual void init() = 0;
 
    virtual bool isMsgAvailable() = 0;

    virtual Msg* receiveMsg() = 0;

    virtual void sendMsg(Msg msg) = 0;
};

#endif