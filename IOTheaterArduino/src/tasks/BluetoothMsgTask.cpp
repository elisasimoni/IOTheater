/**
 * The code defines a class called BluetoothMsgTask that handles incoming Bluetooth messages and
 * updates the settings of a SmartTheater object accordingly.
 * 
 * @param theater The `theater` parameter is an instance of the `SmartTheater` class. It represents the
 * smart theater system and is used to access and control various components of the theater, such as
 * the music system, curtains, and stage lights. The `BluetoothMsgTask` class uses the `the
 */
#include "BluetoothMsgTask.h"
#include <Arduino.h>
#include <ArduinoJson.h>
#include "../kernel/MsgServiceBluetooth.h"
#include "../model/SmartTheater.h"
#include "config.h"



BluetoothMsgTask::BluetoothMsgTask(SmartTheater* theater) {
    channel = new MsgServiceBluetooth(RX_PIN, TX_PIN);
    channel->init();
    this->theater = theater;
}

void BluetoothMsgTask::tick() {
    if (channel->isMsgAvailable()) {
        Msg* msg = channel->receiveMsg();
        String content = msg->getcontent();
        delete(msg);
        handleContent(content);
    } else {
        notify();
    }
}

void BluetoothMsgTask::handleContent(String content) {

        
        DynamicJsonDocument json(100);
        DeserializationError error = deserializeJson(json,content); 

        if (!error) {

            if(json.containsKey("A")){ //routineDuration
                unsigned long routineDuration = json["A"].as<unsigned long>();
                theater->setRoutineDuration(routineDuration*60000);
                theater->setShow();
                
           }
            
            if(json.containsKey("B")) { //stageLightStartTime
                unsigned long stageLightStartTime = json["B"].as<int>();
                stageLightStartTime = stageLightStartTime*1000;
                theater->setStageLightStartTime(stageLightStartTime);

               
            }

             if(json.containsKey("C")) { //stageLightEndTime
                unsigned long stageLightEndTime = json["C"].as<int>();
                stageLightEndTime = stageLightEndTime*1000;
                theater->setStageLightEndTime(stageLightEndTime);

              
            }

            if(json.containsKey("D")){ //musicStartTime
                unsigned long musicStartTime = json["D"].as<int>();
                theater->setMusicStartTime(musicStartTime*1000);   

            }

            if(json.containsKey("E")){ //musicEndTime
                unsigned long musicEndTime = json["E"].as<int>();
                theater->setMusicEndTime(musicEndTime*1000);   

               
            }

            if(json.containsKey("F")){ //volume
                int musicVolume = json["F"].as<int>();
                theater->setMusicVolume(musicVolume);  
             
            }

            if(json.containsKey("G")){ //musicSong          
                int musicSong = json["G"].as<int>();
                theater->setMusicSong(musicSong);  
    
                
            }

             if (json.containsKey("H")) { //stageLightBrightness
                int stageLightBrightness = json["H"].as<int>();
                theater->setStageLightBrightness(stageLightBrightness);


               
            }
            if(json.containsKey("I") && json.containsKey("J") && json.containsKey("K")){ //stageLightColor
                int stageLightColorR = json["I"].as<int>();
                int stageLightColorG = json["J"].as<int>();
                int stageLightColorB = json["K"].as<int>();
                theater->setStageLightColor(stageLightColorR,stageLightColorG,stageLightColorB);
                
            }


        }
  
}

void BluetoothMsgTask::notify() {

    // int musicSong = theater->getMusic()->getSong();
    // int musicVolume = theater->getMusic()->getVolume();
    // int curtainsState = theater->getCurtains()->getPercentage();
    // int stageLightBrightness = theater->getStageLightSystem()->getBrightness();
    // int stageLightColorR = theater->getStageLightSystem()->getR();
    // int stageLightColorG = theater->getStageLightSystem()->getG();
    // int stageLightColorB = theater->getStageLightSystem()->getB();

    // int routineDuration = theater->getRoutineDuration();
    // int showStartTime = theater->getCurrentTime();

  
    // String updateString = "{";
    // updateString += "\"rD\": " + String(routineDuration) + ",";
    // updateString += "\"sST\": " + String(showStartTime) + ",";
    // updateString += "\"mS\": " + String(musicSong) + ",";
    // updateString += "\"mV\": " + String(musicVolume) + ",";
    // updateString += "\"cS\": " + String(curtainsState) + ",";
    // updateString += "\"sLB\": " + String(stageLightBrightness) + ",";

    // updateString += "\"sLCr\": " + String(stageLightColorR) + ",";
    // updateString += "\"sLCg\": " + String(stageLightColorG) + ",";
    // updateString += "\"sLCb\": " + String(stageLightColorB);
    // updateString += "}";
    // delay(500);
    // Serial.println(updateString);
}