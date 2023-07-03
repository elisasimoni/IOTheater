#ifndef __CURTAINSTASK_
#define __CURTAINSTASK_

#include "kernel/Task.h"
#include "model/Curtains.h"
#include "model/SmartTheater.h"


class CurtainsTask : public Task {
public:
    CurtainsTask(SmartTheater* theater);
   
    void init(int period);
    void tick();
private:
    SmartTheater* theater;
    Curtains* curtains;
    double startTime, endTime;
    void setCurtainsOpen();
    void setCurtainsClose();
    void setCurtainsStop();
    void setCurtainsMoving();
    enum {OPEN, CLOSE, STOP, MOVING} state;


};






#endif