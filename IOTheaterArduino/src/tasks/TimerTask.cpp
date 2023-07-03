/**
 * The TimerTask class is used to manage the timing and state of a theater show.
 * 
 * @param theater The `theater` parameter is a pointer to a `SmartTheater` object. It is used to access
 * and manipulate the state of the theater show.
 */

#include "TimerTask.h"
#include "../config.h"


TimerTask::TimerTask(SmartTheater* theater) {
    this->theater = theater;

}
/**
 * The `init` function initializes the `TimerTask` object with a given period and sets the start time,
 * current time, and state variables.
 * 
 * @param period The "period" parameter represents the time interval at which the TimerTask should be
 * executed. It determines how often the TimerTask's code will be run.
 */

void TimerTask::init(int period) {
    Task::init(period);
    this->startTime = 0;
    this->currentTime = 0;
    this->state = INACTIVE;

}

/**
 * The `tick()` function updates the current time and performs different actions based on the current
 * state of the theater show.
 */
void TimerTask::tick() {

    currentTime = millis();

    switch (state) {
        /* The `case INACTIVE` block is checking if the theater show is currently active. If
        `theater->isShow()` returns true, it means that the show is active, and the `setActive()`
        function is called to change the state to "ACTIVE". If the show is not active, the code
        continues to the next case in the switch statement. */
        case INACTIVE: {
            
            if(theater->isShow()){
                setActive();             
            }
            break;
        }

        /* The `case ACTIVE` block is executed when the state of the theater show is set to "ACTIVE". */
        case ACTIVE: {

            unsigned long temp=currentTime-startTime;

            theater->setCurrentTime(temp);
            if(currentTime-startTime >= theater->getRoutineDuration()){
                theater->setNoShow(); // The show is over   
                setInactive();
            }
            
            break;
        }

        default: {
            break;
        }
    }
}

/**
 * The function sets the state of the TimerTask object to ACTIVE and records the current time.
 */
void TimerTask::setActive() {
    this->state = ACTIVE;
    startTime = millis();
    
}

/**
 * The function sets the state of the TimerTask object to INACTIVE and resets the startTime and
 * currentTime variables to 0.
 */
void TimerTask::setInactive() {
    this->state = INACTIVE;
    startTime = 0;
    currentTime = 0;
}

