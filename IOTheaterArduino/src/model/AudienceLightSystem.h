#ifndef __AUDIENCELIGHTSYSTEM__
#define __AUDIENCELIGHTSYSTEM__
#include "devices/Light.h"


class AudienceLightSystem{
private:
    Light* light;

public:
    void turnOn();
    void turnOff();
    AudienceLightSystem(int lightPIN);
    
};


#endif