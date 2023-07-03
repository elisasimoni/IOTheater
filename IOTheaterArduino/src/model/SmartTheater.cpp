/**
 * The code defines a SmartTheater class in C++ with various methods to control the curtains, music,
 * stage lights, and audience lights.
 * 
 * @param lightAPin The parameter "lightAPin" is the pin number for the audience light system. It is
 * used to control the audience lights in the smart theater.
 * @param lightPIN_r The parameter `lightPIN_r` is the pin number for the red LED of the stage light
 * system.
 * @param lightPIN_g The parameter `lightPIN_g` is the pin number for the green LED of the stage light
 * system in the SmartTheater class.
 * @param lightPIN_b The parameter `lightPIN_b` is the pin number for the blue LED of the stage light
 * system in the SmartTheater class.
 * @param curtainsPIN The curtainsPIN parameter is the pin number used to control the curtains in the
 * SmartTheater class.
 * @param musicPIN The musicPIN parameter is the pin number used to connect the music system in the
 * SmartTheater class.
 */
#include "SmartTheater.h"
#include <TimerOne.h>

SmartTheater::SmartTheater(int lightAPin, int lightPIN_r, int lightPIN_g, int lightPIN_b, int curtainsPIN, int musicPIN) {
    this->curtains = new Curtains(curtainsPIN);
    this->music = new Music(musicPIN);
    this->stageLightSystem = new StageLightSystem(lightPIN_r, lightPIN_g, lightPIN_b);
    this->audienceLightSystem = new AudienceLightSystem(lightAPin);
    this->state = NO_SHOW;
    this->timer = 0;
    this->currentTime = 0;
    
}


/**
 * The function returns the stage light system of the smart theater.
 * 
 * @return a pointer to an object of type StageLightSystem.
 */
StageLightSystem* SmartTheater::getStageLightSystem() {
    return this->stageLightSystem;
}


/**
 * The function returns the audience light system of a smart theater.
 * 
 * @return The method is returning a pointer to an object of type AudienceLightSystem.
 */
AudienceLightSystem* SmartTheater::getAudienceLightSystem() {
    return this->audienceLightSystem;
}


/**
 * The getCurtains() function returns a pointer to the curtains object in the SmartTheater class.
 * 
 * @return The getCurtains() function is returning the curtains object of the SmartTheater class.
 */
Curtains* SmartTheater::getCurtains() {
    return this->curtains;
}


/**
 * The function returns a pointer to the music object in the SmartTheater class.
 * 
 * @return The music object is being returned.
 */
Music* SmartTheater::getMusic() {
    return this->music;
}


/**
 * The function isShow() returns true if the state of the SmartTheater object is SHOW.
 * 
 * @return a boolean value.
 */
bool SmartTheater::isShow() {
    return this->state == SHOW;
}

bool SmartTheater::isNoShow() {
    return this->state == NO_SHOW;
}

void SmartTheater::setNoShow() {
    this->state = NO_SHOW;
}

void SmartTheater::setShow() {
    this->state = SHOW;
}


bool SmartTheater::getState() {
    if (this->isShow()) {
       return true;
    } else {
       return false;
    }
}

// Curtains
void SmartTheater::setCurtainsOpenPercentage(int percentage) {
    this->curtains->setPercentage(percentage);
}

// Music
void SmartTheater::setMusicVolume(double volume) {
    this->music->setVolume(volume);
}

void SmartTheater::setMusicSong(int song) {
    this->music->setSong(song);
}

void SmartTheater::setMusicFrequency(int frequency) {
    this->music->setFrequency(frequency);
}

void SmartTheater::setMusicStartTime(double startTime) {
    this->music->setStartTime(startTime);
}

void SmartTheater::setMusicEndTime(double endTime) {
    this->music->setEndTime(endTime);
}


// Stage and Audience Light
void SmartTheater::setStageLightColor(int r, int g, int b) {
    this->stageLightSystem->setRGB(r, g, b);
}

void SmartTheater::setStageLightStartTime(double startTime) {
    this->stageLightSystem->setStartTime(startTime);
}

void SmartTheater::setStageLightEndTime(double endTime) {
    this->stageLightSystem->setEndTime(endTime);
}

void SmartTheater::setStageLightBrightness(int brightness) {
    this->stageLightSystem->setBrightness(brightness);
}

// Tempo routine
unsigned long SmartTheater::getRoutineDuration() {
    return this->timer;
}

void SmartTheater::setRoutineDuration(unsigned long timer) {
    this->timer = timer;
}

void SmartTheater::setCurrentTime(unsigned long currentTime) {
    this->currentTime = currentTime;
}

unsigned long SmartTheater::getCurrentTime() {
    return this->currentTime;
}