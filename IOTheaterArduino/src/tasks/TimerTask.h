#ifndef __TIMERTASK__
#define __TIMERTASK__

#include <Arduino.h>
#include "kernel/Task.h"
#include "model/SmartTheater.h"



class TimerTask : public Task {
public:
    TimerTask(SmartTheater* theater);
   
    void init(int period);
    void tick();
    void setActive();
    void setInactive();
private:
    SmartTheater* theater;
    unsigned long startTime, currentTime,delayTime;
    enum {ACTIVE,INACTIVE} state;


};




#endif