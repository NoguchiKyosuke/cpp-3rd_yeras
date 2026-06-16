#include "RepeatMessage.h"
#include <string>

RepeatMessage::RepeatMessage() : Message() {
    n_roop = 1;
}

RepeatMessage::RepeatMessage(int n) : Message() {
    n_roop = n;
}

const char* RepeatMessage::getMessage() const {
    std::string temp;
    for(int i = 0; i < n_roop; i++) {
        temp += "abc";
    }
    return temp.c_str();
}