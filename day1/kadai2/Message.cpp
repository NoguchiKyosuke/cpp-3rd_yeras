#include "Message.h"
#include <string>
#include <iostream>

Message::Message () {
    message = nullptr;
}

Message::Message (const char* str) {
    message = str;
}

const char* Message::getMessage () const{
    return message;
}

void Message::setMessage (const char* str) {
    message = str;
}

std::ostream& operator<< (std::ostream& os, const Message& m) {
    os << m.getMessage();
    return os;
}

std::istream& operator>> (std::istream& is, Message& m) {
    static std::string temp;
    is >> temp;
    m.setMessage(temp.c_str());
    return is;
}