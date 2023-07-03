/**
 * The AudienceLightSystem class controls a LED light by turning it on and off.
 * 
 * @param lightPIN The lightPIN parameter is an integer that represents the pin number of the LED used
 * in the AudienceLightSystem.
 */
#include "AudienceLightSystem.h"
#include "devices/Led.h"

AudienceLightSystem::AudienceLightSystem(int lightPIN){
    this->light = new Led(lightPIN);
}

void AudienceLightSystem::turnOn(){
    this->light->switchOn();
}

void AudienceLightSystem::turnOff(){
    this->light->switchOff();
}