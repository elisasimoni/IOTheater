#ifndef __LEDRGB__
#define __LEDRGB__

#include "LightRGB.h"

class LedRGB: public LightRGB { 
public:
  LedRGB(int pinR, int pinG, int pinB);
  void setColor(int r, int g, int b);
  void switchOff();    
protected:
  int pinR, pinG, pinB;  
};

#endif