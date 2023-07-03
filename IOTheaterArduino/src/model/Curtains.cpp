/**
 * The code defines a class called "Curtains" that controls the opening and closing of curtains using a
 * servo motor.
 * 
 * @param servoPIN The `servoPIN` parameter is the pin number to which the servo motor is connected. It
 * is used to initialize the ServoMotorImpl object.
 */

#include "Curtains.h"
#include "devices/servo_motor_impl.h"
#include "config.h"

/**
 * The Curtains constructor initializes a new instance of the Curtains class with a specified servo
 * motor pin and sets the open percentage to 0.
 * 
 * @param servoPIN The servoPIN parameter is the pin number to which the servo motor is connected. It
 * is used to initialize the ServoMotorImpl object.
 */
Curtains::Curtains(int servoPIN){
    this->servoMotor = new ServoMotorImpl(servoPIN);
    this->openPercentage = 0;
}

/**
 * The open function turns on the servo motor for the curtains.
 */
void Curtains::open(){
    this->servoMotor->on();
}

/**
 * The close function turns off the servo motor for the curtains.
 */
void Curtains::close(){
    this->servoMotor->off();
}

/**
 * The function "plainOpen()" opens the curtains fully by setting the servo motor position to the open
 * angle and setting the open percentage to 100%.
 */
void Curtains::plainOpen() {
    this->servoMotor->setPosition(OPEN_ANGLE);  
    this->openPercentage = 180; // Imposta la percentuale di apertura al 100%
    
   
}

/**
 * The function "plainClose" closes the curtains by setting the servo motor position to a specific
 * angle and setting the open percentage to 0%.
 */
void Curtains::plainClose() {
    this->servoMotor->setPosition(CLOSE_ANGLE);
    this->openPercentage = 0; // Imposta la percentuale di apertura a 0%
}

/**
 * The function sets the position of the curtains based on a given percentage value.
 * 
 * @param percentage The "percentage" parameter represents the desired percentage of the curtains'
 * opening. It should be an integer value between 0 and 100, where 0 represents fully closed curtains
 * and 100 represents fully open curtains.
 */
void Curtains::setPercentage(int percentage) {
    int targetPosition = map(percentage, 0, 100, CLOSE_ANGLE, OPEN_ANGLE);
    this->servoMotor->setPosition(targetPosition);
    this->openPercentage = percentage; // Salva la nuova percentuale di apertura
}


/**
 * The function "getPercentage" returns the open percentage of the curtains.
 * 
 * @return The open percentage of the curtains.
 */
int Curtains::getPercentage(){
    return this->openPercentage;
}

/**
 * The function sets the start time for the Curtains object.
 * 
 * @param startTime The startTime parameter is a double data type, which represents the time at which
 * the curtains should start opening or closing.
 */
void Curtains::setStartTime(double startTime){
    this->startTime = startTime;
}

/**
 * The function sets the end time for the Curtains object.
 * 
 * @param endTime The endTime parameter is a double that represents the time at which the curtains
 * should be closed.
 */
void Curtains::setEndTime(double endTime){
    this->endTime = endTime;
}

/**
 * The function "getEndTime" returns the end time of the curtains.
 * 
 * @return The method is returning the value of the endTime variable, which is of type double.
 */
double Curtains::getEndTime(){
    return this->endTime;
}

/**
 * The function `getStartTime` returns the start time of the curtains.
 * 
 * @return The start time of the curtains.
 */
double Curtains::getStartTime(){
    return this->startTime;
}

