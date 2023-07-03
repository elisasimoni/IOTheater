#ifndef __ESPBOARD__
#define __ESPBOARD__

#include <Arduino.h>
#include "devices/Pir.h"
#include "devices/Led.h"

class ESPBoard {
    private:
        bool presence;
        Pir* pir;
        Light* light;

    public:

        ESPBoard(int pirPIN, int lightPin);

        bool isActorSpotlight();

        void lightSwitchOff();
        void lightSwitchOn();
};

#endif