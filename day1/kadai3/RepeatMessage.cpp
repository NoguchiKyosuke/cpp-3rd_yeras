#include "RepeatMessage.h"

RepeatMessage::RepeatMessage() : Message() {
    n_loop = 1;
}

RepeatMessage::RepeatMessage(int n) : Message() {
    n_loop = n;
}

std::ostream& operator << (std::ostream& os, const RepeatMessage& m) {
    for (int i = 0; i < m.n_loop; i++) {
        os << m.getMessage();
    }
    return os;
}