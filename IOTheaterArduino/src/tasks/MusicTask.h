#ifndef __MUSICTASK__
#define __MUSICTASK__
#include "model/SmartTheater.h"
#include "kernel/Task.h"


class MusicTask : public Task{
private:
    SmartTheater* theater;
    Music* music;
    enum {PLAY, STOP} state;
    double startTime, endTime;
    int song,volume;
    // void setSong();
    // void getSong();
    void setStateOn();
    void setStateOff();
    void Tetris();
    void TronoDiSpade();
    void StarWars();

public:
    MusicTask(SmartTheater* theater);
    void init(int period);
    void tick();

};



#endif