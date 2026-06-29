#include "Message.h"

Message::Message(): message() {
}

Message::Message(const std::string& message_string) {
  message.push_back(message_string);
}

Message::Message(const std::vector<std::string>& message_vector) {
  for (size_t i = 0; i < message_vector.size(); ++i) {
    message.push_back(message_vector[i]);
  }
}

Message::~Message() {
  delete [] message;
}

// void Message::setMessage (const char* _message) {
//   if (message != nullptr) delete [] message;
//   message.push_back(std::string(_message));
// }

// char* Message::getMessage (int message_id) {
//   return message[message_id];
// }

void Message::showAllMessages (void) {
  for (size_t i = 0; i < message.size(); ++i) {
    std::cout << message[i] << std::endl;
  }
}