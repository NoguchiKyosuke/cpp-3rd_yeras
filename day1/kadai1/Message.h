#pragma once

#include <stdio.h>

class Message {
private:
    char* message;
public:
    Message ();
    Message (char* str);
    char* getMessage ();
    void setMessage (char* str);
}