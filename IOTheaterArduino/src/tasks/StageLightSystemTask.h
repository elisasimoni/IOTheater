#ifndef __STAGE_LIGHT_SYSTEM_TASK__
#define __STAGE_LIGHT_SYSTEM_TASK__
#include "kernel/Task.h"
#include "model/SmartTheater.h"
#include "model/StageLightSystem.h"

class StageLightSystemTask : public Task{
private:
    SmartTheater* theater;
    StageLightSystem* stageLightSystem;
    unsigned long startTime, endTime;
    enum {OFF, ON} state;
    void setStateOn();
    void setStateOff();
public:
    StageLightSystemTask(SmartTheater* theater);
    void init(int period);
    void tick();

};

#endif
