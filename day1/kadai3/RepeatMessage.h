#include "Message.h"

class RepeatMessage : public Message {
private:
    int n_roop;
public:
    RepeatMessage();
    RepeatMessage(int n);
    const char* getMessage() const;  
};