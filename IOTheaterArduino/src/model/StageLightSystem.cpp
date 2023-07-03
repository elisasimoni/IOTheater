/**
 * The above code defines a StageLightSystem class in C++ that controls an RGB LED light.
 * 
 * @param lightPINR The parameter "lightPINR" represents the pin number for the red component of the
 * RGB LED in the stage light system. It is an integer value that specifies the pin number on the
 * microcontroller board to which the red LED is connected.
 * @param lightPING The parameter "lightPING" represents the pin number for the green component of the
 * RGB LED in the stage light system. It is used to control the intensity of the green color in the RGB
 * color model.
 * @param lightPINB The parameter "lightPINB" represents the pin number for the blue component of the
 * RGB LED in the stage light system. It is an integer value that specifies the pin number on the
 * microcontroller board to which the blue LED is connected.
 */
#include "StageLightSystem.h"
#include "devices/LedRGB.h"

StageLightSystem::StageLightSystem(int lightPINR, int lightPING, int lightPINB){
    this->light = new LedRGB(lightPINR, lightPING, lightPINB);
    this->r = 0;
    this->g = 0;
    this->b = 0;
    this->startTime = 0;
    this->endTime = 0;
    this->brightness = 0;
}

/**
 * The function turnOn sets the color of the light to the specified RGB values.
 * 
 * @param r The value for the red component of the light color. It represents the intensity of the red
 * color in the RGB color model. The value should be between 0 and 255, where 0 represents no red and
 * 255 represents maximum intensity of red.
 * @param g The parameter "g" represents the intensity of the green color in the stage light system.
 * @param b The parameter "b" represents the value for the blue component of the RGB color.
 */
void StageLightSystem::turnOn(int r, int g, int b){
    this->light->setColor(r,g,b);
}

/**
 * The function turnOff() turns off the stage light system by switching off the light.
 */
void StageLightSystem::turnOff(){
    this->light->switchOff();
}

/**
 * The function sets the start time for the stage light system.
 * 
 * @param startTime The startTime parameter is an unsigned long data type, which represents the
 * starting time for the stage light system.
 */
void StageLightSystem::setStartTime(unsigned long startTime){
    this->startTime = startTime;
}

/**
 * The function sets the end time for the stage light system.
 * 
 * @param endTime The endTime parameter is an unsigned long variable that represents the time at which
 * the stage light system should stop running.
 */
void StageLightSystem::setEndTime(unsigned long endTime){
    this->endTime = endTime;
}

/**
 * The function sets the brightness of the stage light system.
 * 
 * @param brightness The brightness parameter is an integer value that represents the desired
 * brightness level for the stage lights.
 */
void StageLightSystem::setBrightness(int brightness){
    this->brightness = brightness;
}

/**
 * The function "getStartTime" returns the start time of the stage light system.
 * 
 * @return The start time of the stage light system.
 */
double StageLightSystem::getStartTime(){
    return this->startTime;
}

/**
 * The function "getEndTime" returns the end time of the stage light system.
 * 
 * @return The method is returning the value of the endTime variable, which is of type double.
 */
double StageLightSystem::getEndTime(){
    return this->endTime;
}
/**
 * The function "getBrightness" returns the current brightness value of the StageLightSystem.
 * 
 * @return The brightness value of the StageLightSystem object.
 */

/**
 * The function returns the brightness value of the StageLightSystem.
 * 
 * @return The brightness value of the StageLightSystem object.
 */
int StageLightSystem::getBrightness(){
    return this->brightness;
}

/**
 * The function sets the RGB values for a stage light system.
 * 
 * @param r The value of the red component of the RGB color.
 * @param g The parameter "g" represents the value for the green component of the RGB color.
 * @param b The parameter "b" represents the value for the blue component of the RGB color.
 */
void StageLightSystem::setRGB(int r, int g, int b){
    this->r = r;
    this->g = g;
    this->b = b;
}

/**
 * The function returns the value of the "r" variable in the StageLightSystem class.
 * 
 * @return The value of the variable "r" in the StageLightSystem object.
 */
int StageLightSystem::getR(){
    return this->r;
}

/**
 * The function "getG" returns the value of the variable "g" in the StageLightSystem class.
 * 
 * @return The value of the variable "g" in the StageLightSystem object.
 */
int StageLightSystem::getG(){
    return this->g;
}

/**
 * The function "getB" returns the value of the variable "b" in the StageLightSystem class.
 * 
 * @return The value of the variable "b" in the StageLightSystem object.
 */
int StageLightSystem::getB(){
    return this->b;
}




