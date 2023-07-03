#ifndef __MUSIC__
#define __MUSIC__

#include "devices/Buzzer.h"


class Music {
private:
    Buzzer* music;
    unsigned long startTime;
    unsigned long endTime;
    int frequency;
    int duration;
    int volume;
    int song;


public:
    Music(int musicPin);
    void turnOn(int frequency, int duration);
    void turnOff();
    unsigned long getStartTime();
    unsigned long getEndTime();
    int getFrequency();
    int getDuration();
    void setVolume(int volume);
    int getVolume();
    void setFrequency(int frequency);
    void setDuration(int duration);
    void setStartTime(unsigned long startTime);
    void setEndTime(unsigned long endTime);
    void setSong(int song);
    int getSong();

};

#endif
