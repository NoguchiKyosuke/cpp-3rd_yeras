#include "Message.h"
#include <string>
#include <iostream>
#include <cstring>

Message::Message () {
    message = nullptr;
}

Message::Message (const char* str) {
    message = new char[strlen(str) + 1];
    std::strcpy(message, str);
}

Message::~Message () {
    delete[] message;
}

const char* Message::getMessage () const{
    return message;
}

void Message::setMessage (const char* str) {
    delete[] message;
    message = new char[strlen(str) + 1];
    std::strcpy(message, str);
}

std::ostream& operator<< (std::ostream& os, const Message& m) {
    os << m.getMessage();
    return os;
}

std::istream& operator>> (std::istream& is, Message& m) {
    std::string temp;
    is >> temp;
    m.setMessage(temp.c_str());
    return is;
}