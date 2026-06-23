#pragma once

#include <cstring>

class Message {
private:
    char* message;
public:
    Message ();
    Message (const char* str);
    ~Message ();
    const char* getMessage ();
    void setMessage (const char* str);
};