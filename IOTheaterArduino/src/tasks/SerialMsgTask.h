#ifndef __SERIALMSGTASK__
#define __SERIALMSGTASK__

#include <Arduino.h>
#include "../kernel/Task.h"
#include "kernel/MsgServiceSerial.h"
#include "../model/SmartTheater.h"

class SerialMsgTask : public Task {
private:
    SmartTheater* theater;
    MsgServiceSerial* channel;

    void handleContent(String content);
  
    void notify();

public:
 
    SerialMsgTask(SmartTheater* theater);
   
    void tick();
};

#endif