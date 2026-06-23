#pragma once
#include "Message.h"
#include <iostream>

class RepeatMessage : public Message {
private:
    int n_loop;
public:
    RepeatMessage();
    RepeatMessage(int n);
    
    friend std::ostream& operator << (std::ostream& os, const RepeatMessage& m);
};