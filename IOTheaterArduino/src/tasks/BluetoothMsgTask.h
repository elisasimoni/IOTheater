#ifndef __BLUETOOTHMSGTASK__
#define __BLUETOOTHMSGTASK__

#include <Arduino.h>
#include "../kernel/Task.h"
#include "kernel/MsgServiceBluetooth.h"
#include "../model/SmartTheater.h"

class BluetoothMsgTask : public Task {
private:
    SmartTheater* theater;
    MsgServiceBluetooth* channel;

    void handleContent(String content);
  
    void notify();

public:
 
    BluetoothMsgTask(SmartTheater* theater);
   
    void tick();
};

#endif