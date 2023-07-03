#ifndef __STAGELIGHTSYSTEM__
#define __STAGELIGHTSYSTEM__
#include "devices/LightRGB.h"


class StageLightSystem{
private:
    LightRGB* light;
    unsigned long startTime;
    unsigned long endTime;
    int brightness;
    int r;
    int g;
    int b;

    
public:
    void turnOn(int r, int g, int b);
    void turnOff();
    void setRGB(int r, int g, int b);
    void setStartTime(unsigned long startTime);
    void setEndTime(unsigned long endTime);
    void setBrightness(int brightness);
    double getStartTime();
    double getEndTime();
    int getBrightness();
    int getR();
    int getG();
    int getB();
    StageLightSystem(int lightPINR, int lightPING, int lightPINB);



};



#endif 