/**
 * The ESPBoard class is responsible for controlling a PIR sensor and an LED light, and provides
 * functions to check for presence and control the light.
 * 
 * @param pirPin pirPin is the pin number to which the PIR (Passive Infrared) sensor is connected on
 * the ESPBoard. This sensor is used to detect motion or presence of a person or object.
 * @param lightPin The lightPin parameter is the pin number to which the LED light is connected on the
 * ESPBoard.
 */
#include "ESPBoard.h"
#include "devices/Pir.h"
#include "devices/Led.h"

ESPBoard::ESPBoard(int pirPin,int lightPin) {
    this->pir = new Pir(pirPin);
    this->pir->calibrate();
    this->light = new Led(lightPin);
    //this->presence = false;
    
}

bool ESPBoard::isActorSpotlight() {
    pir->sync();
    this->presence = pir->isDetected();
    return this->presence;
 
}

void ESPBoard::lightSwitchOff() {
    light->switchOff();
}

void ESPBoard::lightSwitchOn() {
    light->switchOn();
}


