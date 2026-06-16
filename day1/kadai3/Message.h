#pragma once

#include <string>
#include <iostream>

class Message {
friend class RepeatMessage;
private:
    const char* message;
public:
    Message ();
    Message (const char* str);
    const char* getMessage () const;
    void setMessage (const char* str);
    friend std::ostream& operator << (std::ostream& os, const Message& m);
    friend std::istream& operator >> (std::istream& is, Message& m);
};