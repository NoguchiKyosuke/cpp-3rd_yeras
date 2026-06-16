#include "Message.h"

Message::Message () {
    message = "Please set a message.";
}

Message::Message (char* str) {
    message = str;
}

char* Message::getMessage () {
    return message;
}

void Message::setMessage (char* str) {
    message = str;
}