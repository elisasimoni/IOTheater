#ifndef __AUDIENCE_LIGHT_SYSTEM_TASK__
#define __AUDIENCE_LIGHT_SYSTEM_TASK__
#include "kernel/Task.h"
#include "model/SmartTheater.h"
#include "model/AudienceLightSystem.h"

class AudienceLightSystemTask : public Task{
private:
    SmartTheater* theater;
    AudienceLightSystem* audienceLightSystem;
    enum {OFF, ON} state;
    void setStateOn();
    void setStateOff();
public:
    AudienceLightSystemTask(SmartTheater* theater);
    void init(int period);
    void tick();

};

#endif
