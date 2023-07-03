#ifndef __MSG__
#define __MSG__

#include <Arduino.h>



class Msg {
private:
    String content;

public:
   
    Msg(String content) {
        this->content = content;
    }


    String getcontent() {
        return this->content;
    }
};

#endif