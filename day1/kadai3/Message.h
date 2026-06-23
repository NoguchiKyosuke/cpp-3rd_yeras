#pragma once
#include <iostream>

class Message {
private:
    char* message;
public:
    Message ();
    Message (const char* str);
    ~Message ();
    const char* getMessage () const;
    void setMessage (const char* str);
    friend std::ostream& operator << (std::ostream& os, const Message& m);
    friend std::istream& operator >> (std::istream& is, Message& m);
};