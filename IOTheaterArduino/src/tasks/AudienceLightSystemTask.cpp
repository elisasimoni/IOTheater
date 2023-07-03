
/**
 * The AudienceLightSystemTask class is responsible for managing the state of the audience light system
 * in a smart theater.
 * 
 * @param smartTheater A pointer to an object of type SmartTheater, which represents a smart theater
 * system.
 */
#include "AudienceLightSystemTask.h"
#include "config.h"

AudienceLightSystemTask::AudienceLightSystemTask(SmartTheater* smartTheater){
    this->theater = smartTheater;
    this->audienceLightSystem = smartTheater->getAudienceLightSystem();
    this->state = OFF;
    

}

void AudienceLightSystemTask::tick(){
    switch(state){
        case OFF:{
            if(theater->isNoShow()){
               
                    setStateOn(); 
                
            }
           break;
            
        }
        case ON:{
            if(theater->isShow()){
                setStateOff();
            }
            break;
            
        }
        default:{
            break;
        }
    }
}

void AudienceLightSystemTask::setStateOn(){
    this->state = ON;
    this->audienceLightSystem->turnOn();
}

void AudienceLightSystemTask::setStateOff(){
    this->state = OFF;
    this->audienceLightSystem->turnOff();
}

void AudienceLightSystemTask::init(int period){
     Task::init(period);
}
