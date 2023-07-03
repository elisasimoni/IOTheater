#ifndef __SMARTTHEATER__
#define __SMARTTHEATER__

#include "StageLightSystem.h"
#include "AudienceLightSystem.h"
#include "Curtains.h"
#include "Music.h"
#include "../config.h"

class SmartTheater {
private:
    StageLightSystem* stageLightSystem;
    AudienceLightSystem* audienceLightSystem;
    Curtains* curtains;
    Music* music;
    unsigned long timer;
    unsigned long currentTime;
    enum { SHOW, NO_SHOW } state;
public:
    //Constructor
    SmartTheater(int lightAPin, int lightPIN_r, int lightPIN_g, int lightPIN_b, int curtainsPIN, int musicPIN);

    //Getters
    StageLightSystem* getStageLightSystem();
    AudienceLightSystem* getAudienceLightSystem();
    Curtains* getCurtains();
    Music* getMusic();
    AudienceLightSystem* getAudienceLight();

    
   
    //Theater state
    bool isShow();
    bool isNoShow();
    void setNoShow();
    void setShow();
    bool getState();

    //Curtains
    void setCurtainsOpenPercentage(int percentage);

    // Music
    void setMusicVolume(double volume);
    void setMusicSong(int song);
    void setMusicFrequency(int frequency);
    void setMusicStartTime(double startTime);
    void setMusicEndTime(double endTime);

    //Stage and Audience Light
    void setStageLightColor(int r, int g, int b);
    void setStageLightStartTime(double startTime);
    void setStageLightEndTime(double endTime);
    void setStageLightBrightness(int brightness);
    

    // Tempo routine
    void setRoutineDuration(unsigned long timer);
    unsigned long getRoutineDuration();
    void setCurrentTime(unsigned long currentTime);
    unsigned long getCurrentTime();

};

#endif
