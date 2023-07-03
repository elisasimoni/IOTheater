/**
 * The MusicTask class is responsible for controlling the music in a smart theater based on the current
 * time and show status.
 * 
 * @param smartTheater A pointer to an instance of the SmartTheater class, which represents a smart
 * theater system.
 */
#include "MusicTask.h"
#include "config.h"
#include "TimerTask.h"
#include "../model/SmartTheater.h" 
#include "../model/Music.h"
#include <Arduino.h>

MusicTask::MusicTask(SmartTheater* smartTheater){
    this->theater = smartTheater;
    this->music = smartTheater->getMusic();
    this->state = STOP;

}   

void MusicTask::tick(){
    switch (this->state){
        case STOP:{

            /* The code is checking if the theater is currently showing and if the current time is
            within the specified start and end time of the music. If both conditions are true, it
            calls the `setStateOn()` function to set the state of the music task to "PLAY",
            indicating that the music should be turned on. */
            if(theater->isShow() && (theater->getCurrentTime() >= music->getStartTime() && theater->getCurrentTime() <= music->getEndTime())){
                setStateOn();
            }
            break;
        }

        case PLAY:{
            /* The code `music->turnOn(music->getVolume(),music->getSong());` is calling the `turnOn`
            function of the `music` object with the volume and song parameters obtained from the
            `music` object. This function is responsible for turning on the music with the specified
            volume and playing the specified song. */
            music->turnOn(music->getVolume(),music->getSong());
            if(theater->isNoShow() || theater->getCurrentTime() > music->getEndTime()){
               setStateOff();
            }
            break;
        }
        default:{
            break;
        }
    }
}

void MusicTask::setStateOn(){
    this->state = PLAY;
}
void MusicTask::setStateOff(){
    this->state = STOP;
    this->music->turnOff();
    this->volume=0;
    this->song=0;
}


void MusicTask::init(int period){
    Task::init(period);
}




