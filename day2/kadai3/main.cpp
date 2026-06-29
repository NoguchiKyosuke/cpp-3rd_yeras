#include <iostream>
#include <vector>
#include "Message.h"

int main (int argc, char *argv[]) {
  printf("オブジェクトの生成とshowAllMessages()の呼び出しのテスト\n");
  Message obj1("Hello, World!");
  obj1.showAllMessages();

  printf("addMessage()の呼び出しのテスト\n");
  obj1.addMessage("additional message.");
  obj1.showAllMessages();

  printf("getMessage()の呼び出しのテスト\n");
  std::cout << "Message 0: " << obj1.getMessage(0) << std::endl;
  std::cout << "Message 1: " << obj1.getMessage(1) << std::endl;

  printf("showAllMessages()の呼び出しのテスト\n");
  std::vector<std::string> messages = {"Message 1", "Message 2", "Message 3"};
  Message obj2(messages);
  obj2.showAllMessages();

  printf("getNMessages()の呼び出しのテスト\n");
  std::cout << "Number of messages in obj1: " << obj1.getNMessages() << std::endl;

  printf("デストラクタのテスト\n");
  obj1.~Message();
  obj1.showAllMessages();

  return 0;
}