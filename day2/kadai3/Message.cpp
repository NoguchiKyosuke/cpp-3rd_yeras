#include <stdlib.h>
#include <string.h>
#include <string>
#include "Message.h"

Message::Message(): message() {
}

Message::Message(const std::string& message_string) {
  message[0] = new char [message_string.length() + 1];
  strcpy (message[0], message_string.c_str());
}

// コピーコンストラクタを追加
Message::Message(const std::vector<std::string>& message_vector) {
  message = new char [message_vector.size() + 1];
  for (size_t i = 0; i < message_vector.size(); ++i) {
    message[i] = new char [message_vector[i].length() + 1];
    strcpy (message[i], message_vector[i].c_str());
  }
}

Message::~Message() {
  if (message != nullptr) delete [] message;
}

// void Message::setMessage (const char* _message) {
//   if (message != nullptr) delete [] message;
//   message.push_back(std::string(_message));
// }

// char* Message::getMessage (int message_id) {
//   return message[message_id];
// }