#pragma once

#include <stdio.h>

class Message {
private:
    const char* message;
public:
    Message ();
    Message (const char* str);
    const char* getMessage ();
    void setMessage (const char* str);
};