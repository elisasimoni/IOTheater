#ifndef __ACTORPRESENCETASK__
#define __ACTORPRESENCETASK__

#include "kernel/Task.h"
#include "model/ESPBoard.h"


class ActorPresenceTask : public Task {
private:
    ESPBoard* espboard;
    
public:

    ActorPresenceTask(ESPBoard* espboard);

    void tick();
};

#endif