#include <iostream>
#include "Message.h"

int main(int argc, char* argv[]) {
    Message obj;
    obj.setMessage("Hello, World!");
    std::cout << obj.getMessage() << std::endl;

    return 0;
}