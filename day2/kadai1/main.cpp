#include <iostream>
#include "Message.h"

int main (int argc, char *argv[]) {
  Message obj1("Hello World.");
  Message obj2 = obj1;
  std::cout << obj2 << std::endl;
  printf("obj1: %p\n", obj1.getMessage());
  printf("obj2: %p\n", obj2.getMessage());

  return 0;
}