#ifndef __CURTAINS__
#define __CURTAINS__

#include "devices/servo_motor.h"

class Curtains{
private:
    ServoMotor* servoMotor;
    int openPercentage;
    double startTime, endTime;
    
public:
    void open();
    void close();
    void plainOpen();
    void plainClose();
    void setPercentage(int percentage);
    int getPercentage();
    void setStartTime(double startTime);
    void setEndTime(double endTime);
    double getEndTime();
    double getStartTime();
    Curtains(int servoPIN);
};


#endif


