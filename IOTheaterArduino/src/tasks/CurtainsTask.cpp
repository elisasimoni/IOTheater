/**
 * The CurtainsTask class controls the opening and closing of curtains in a smart theater based on the
 * state of the theater's show.
 * 
 * @param theater A pointer to a SmartTheater object, which represents the theater where the curtains
 * are located.
 */
#include "Arduino.h"
#include "CurtainsTask.h"
#include "model/SmartTheater.h"
#include "../config.h"


CurtainsTask::CurtainsTask(SmartTheater* theater) {
    this->theater = theater;
    this->curtains = theater->getCurtains();
    this->state = STOP;
}

void CurtainsTask::tick() {
    switch (state) {
        case CLOSE: {
            
           /* The code block `if(theater->isShow()){ curtains->open(); curtains->plainOpen();
           setCurtainsOpen(); }` is checking if the theater is currently showing a performance. If
           it is, then it opens the curtains by calling the `open()` and `plainOpen()` methods of
           the `curtains` object. It also calls the `setCurtainsOpen()` method to update the state
           of the curtains task. */
            if(theater->isShow()){
                
                setCurtainsOpen();      
            }
            break;
        }

        case OPEN: {
           
            
            /* The code block `curtains->close(); if(theater->isNoShow()){ curtains->open();
            curtains->plainClose(); setCurtainsStop(); }` is checking if the theater is not showing
            a performance. If it is not, then it closes the curtains by calling the `close()` method
            of the `curtains` object. It also calls the `open()` and `plainClose()` methods of the
            `curtains` object to update the state of the curtains and set them to a partially closed
            position. Finally, it calls the `setCurtainsStop()` method to update the state of the
            curtains task to STOP. */
            curtains->close();
            
            if(theater->isNoShow()){
                
                setCurtainsStop();

            }
            break;
        }

        /* The `case STOP` block is executed when the state of the curtains task is set to STOP. In
        this block, the `close()` method of the `curtains` object is called, which closes the
        curtains. This means that when the curtains task is in the STOP state, the curtains will be
        closed and remain closed until the state is changed. */
        case STOP: {       
            
            curtains->close();
            setCurtainsClose();
            break;
        }

        default: {
            break;
        }
    }
}

void CurtainsTask::setCurtainsOpen() {
    curtains->open();
    curtains->plainOpen();
    this->state = OPEN;
}

void CurtainsTask::setCurtainsClose() {
    curtains->open();
    curtains->plainClose();
    this->state = CLOSE;
}

void CurtainsTask::setCurtainsStop() {
    this->state = STOP;
}   

void CurtainsTask::init(int period){
    Task::init(period);
}
