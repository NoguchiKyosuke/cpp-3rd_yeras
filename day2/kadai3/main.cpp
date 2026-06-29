#include <iostream>
#include <vector>
#include "Message.h"

int main (int argc, char *argv[]) {
  Message obj1("Hello, World!");

  std::vector<std::string> messages = {"Message 1", "Message 2", "Message 3"};

  Message obj2(messages);

  obj1.showAllMessages();
  obj2.showAllMessages();

  return 0;
}