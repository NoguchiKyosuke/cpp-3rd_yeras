#include "Message.h"

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

const char* Message::getMessage () {
    return message;
}

void Message::setMessage (const char* str) {
    delete[] message;
    message = new char[strlen(str) + 1];
    std::strcpy(message, str);
}