/**
 * The SerialMsgTask class in C++ handles incoming messages from a serial channel and updates the state
 * of a theater system accordingly.
 * 
 * @param theater The "theater" parameter is an instance of the SmartTheater class. It is used to
 * access and retrieve information about the current state of the theater, such as the music song and
 * volume, curtains state, stage light brightness, and stage light color.
 */
#include <Arduino.h>
#include <ArduinoJson.h>
#include "SerialMsgTask.h"



SerialMsgTask::SerialMsgTask(SmartTheater* theater) {
    this->channel = new MsgServiceSerial();
    this->channel->init();
  
    this->theater = theater;
}

void SerialMsgTask::tick() {
    if (channel->isMsgAvailable()) {
        Msg* msg = channel->receiveMsg();
        String content = msg->getcontent();
        delete(msg);
        handleContent(content);
    }
    notify();
}


void SerialMsgTask::handleContent(String content) {

}

void SerialMsgTask::notify() {
    int musicSong = theater->getMusic()->getSong();
    int musicVolume = theater->getMusic()->getVolume();
    int curtainsState = theater->getCurtains()->getPercentage();
    int stageLightBrightness = theater->getStageLightSystem()->getBrightness();
    int stageLightColorR = theater->getStageLightSystem()->getR();
    int stageLightColorG = theater->getStageLightSystem()->getG();
    int stageLightColorB = theater->getStageLightSystem()->getB();

    int state = theater->getState();
    int showStartTime = theater->getCurrentTime();

  
    String updateString = "{";
    updateString += "\"rD\": " + String(state) + ",";
    updateString += "\"sST\": " + String(showStartTime) + ",";
    updateString += "\"mS\": " + String(musicSong) + ",";
    updateString += "\"mV\": " + String(musicVolume) + ",";
    updateString += "\"cS\": " + String(curtainsState) + ",";
    updateString += "\"sLB\": " + String(stageLightBrightness) + ",";

    updateString += "\"sLCr\": " + String(stageLightColorR) + ",";
    updateString += "\"sLCg\": " + String(stageLightColorG) + ",";
    updateString += "\"sLCb\": " + String(stageLightColorB);
    updateString += "}";
    delay(500);
    channel->sendMsg(Msg(updateString));


    

    
}