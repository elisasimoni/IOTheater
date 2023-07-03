/**
 * The code defines a Music class in C++ that controls a buzzer connected to an Arduino board to play
 * tones of specified frequencies and durations.
 * 
 * @param musicPin The musicPin parameter is the pin number to which the buzzer is connected. It is
 * used to initialize the Buzzer object in the Music constructor.
 */
#include "Music.h"
#include "devices/Buzzer.h"
#include "Arduino.h"

/**
 * The Music constructor initializes the Music object with the specified music pin and sets the start
 * time, end time, volume, and song to default values.
 * 
 * @param musicPin The musicPin parameter is the pin number to which the buzzer is connected.
 */
Music::Music(int musicPin) {
    music = new Buzzer(musicPin);
    this->startTime = 0;
    this->endTime = 0;
    this->volume = 0;
    this->song = 0;
}

/**
 * The function "turnOn" plays a tone with a specified frequency and duration.
 * 
 * @param frequency The frequency parameter represents the pitch or tone of the music that will be
 * played. It is usually measured in Hertz (Hz), where a higher value corresponds to a higher pitch and
 * a lower value corresponds to a lower pitch.
 * @param duration The duration parameter specifies the length of time in milliseconds that the tone
 * should be played for.
 */
void Music::turnOn(int frequency, int duration) {
    music->playTone(frequency, duration);
    
}

/**
 * The function turnOff() turns off the music.
 */
void Music::turnOff() {
        
    music->switchOff();
    
}

/**
 * The function "getStartTime" returns the start time of a music object.
 * 
 * @return the value of the variable "startTime" as an unsigned long.
 */
unsigned long Music::getStartTime() {
    return startTime;
}

/**
 * The function "getEndTime" returns the value of the endTime variable.
 * 
 * @return the value of the variable "endTime" which is of type unsigned long.
 */
unsigned long Music::getEndTime() {
    return endTime;
}

/**
 * The function "getFrequency" returns the frequency of the music.
 * 
 * @return The frequency of the music.
 */
int Music::getFrequency() {
    return frequency;
}

/**
 * The function "getDuration" returns the duration of a music object.
 * 
 * @return The duration of the music.
 */
int Music::getDuration() {
    return duration;
}

/**
 * The function sets the start time of a music object.
 * 
 * @param startTime The startTime parameter is an unsigned long data type, which represents the
 * starting time of the music.
 */
void Music::setStartTime(unsigned long startTime) {
    this->startTime = startTime;
}

/**
 * The function sets the end time of a music object.
 * 
 * @param endTime The `endTime` parameter is an unsigned long integer that represents the end time of a
 * music track.
 */
void Music::setEndTime(unsigned long endTime) {
    this->endTime = endTime;
}

/**
 * The function sets the frequency of a music object.
 * 
 * @param frequency The "frequency" parameter is an integer that represents the frequency of the music.
 */
void Music::setFrequency(int frequency) {
    this->frequency = frequency;
}

/**
 * The function sets the volume of the music.
 * 
 * @param volume The volume parameter is an integer that represents the desired volume level for the
 * music.
 */
void Music::setVolume(int volume) {
    this->volume = volume;
}

/**
 * The function "getVolume" returns the current volume of the music.
 * 
 * @return The volume of the music.
 */
int Music::getVolume() {
    return volume;
}
/**
 * The function sets the value of the "song" variable in the Music class.
 * 
 * @param song The parameter "song" is an integer that represents the song number or identifier.
 */
void Music::setSong(int song) {
    this->song = song;
}
/**
 * The function "getSong" returns the value of the variable "song" in the Music class.
 * 
 * @return The `getSong()` function is returning the value of the `song` variable.
 */

int Music::getSong() {
    return song;
}





