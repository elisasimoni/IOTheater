#ifndef __SOUND__
#define __SOUND__

class Sound {
public:
    virtual void playTone(int tone, int duration) = 0;
    virtual void switchOff() = 0;
  
};

#endif
