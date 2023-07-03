/**
 * The StageLightSystemTask class is responsible for controlling the stage light system in a theater
 * based on the current show and time.
 * 
 * @param smartTheater A pointer to an instance of the SmartTheater class, which represents the theater
 * system.
 */
#include "StageLightSystemTask.h"
#include "config.h"
#include <Arduino.h>

StageLightSystemTask::StageLightSystemTask(SmartTheater* smartTheater){
    this->theater = smartTheater;
    this->stageLightSystem = smartTheater->getStageLightSystem();
    this->state = ON;

}

void StageLightSystemTask::tick(){
    
    switch(state){
        case OFF:{
            if(theater->isShow() && (theater->getCurrentTime() >= stageLightSystem->getStartTime() && theater->getCurrentTime() <= stageLightSystem->getEndTime()) ){
                setStateOn();             
                
            }
           break;
            
        }
        case ON:{
                                   
            if(theater->isNoShow() || theater->getCurrentTime() >= stageLightSystem->getEndTime()){
                setStateOff();
            }
            
            break;
            
        }
        default:{
            break;
        }
    }
}

/**
 * The function `setStateOn()` turns on the stage light system and updates its state.
 */
void StageLightSystemTask::setStateOn(){
    
    this->stageLightSystem->turnOn(stageLightSystem->getR(), stageLightSystem->getG(), stageLightSystem->getB());
    this->state = ON;
    
}

/**
 * The function `setStateOff` turns off the stage light system by setting the state to OFF, turning off
 * the lights, and setting the RGB values to 0.
 */
void StageLightSystemTask::setStateOff(){
    this->state = OFF;
    this->stageLightSystem->turnOff();
    this->stageLightSystem->setRGB(0,0,0);
}

void StageLightSystemTask::init(int period){
     Task::init(period);
}
