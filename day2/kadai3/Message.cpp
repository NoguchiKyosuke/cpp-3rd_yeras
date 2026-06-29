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
  message.clear();
  message.shrink_to_fit();
}

void Message::addMessage (const std::string& message_string) {
  message.push_back(message_string);
}

std::string Message::getMessage (int message_id) {
  return message[message_id];
}

void Message::showAllMessages (void) {
  for (size_t i = 0; i < message.size(); ++i) {
    std::cout << message[i] << std::endl;
  }
}

int Message::getNMessages(void) {
  return message.size();
}