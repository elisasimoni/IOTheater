#include "ActorPresenceTask.h"
#include "config.h"


/**
 * The ActorPresenceTask constructor initializes an instance of the class by setting the espboard
 * member variable and turning off the light switch on the ESP board.
 * 
 * @param espboard An object of type ESPBoard, which represents the ESP board used in the project.
 */
ActorPresenceTask::ActorPresenceTask(ESPBoard* espboard) {
    this->espboard = espboard;
    this->espboard->lightSwitchOff();
}

/**
 * The tick function checks if an actor is in the spotlight and turns on or off the light accordingly.
 */
void ActorPresenceTask::tick() {
    if (this->espboard->isActorSpotlight()) {
        this->espboard->lightSwitchOn();
    } else {
        this->espboard->lightSwitchOff();
    }
}