#include "Message.h"

Message::Message () {
    message = nullptr;
}

Message::Message (const char* str) {
    message = str;
}

const char* Message::getMessage () {
    return message;
}

void Message::setMessage (const char* str) {
    message = str;
}