#include <iostream>

class Message {
private:
  char* message;

public:
  Message();
  // コピーコンストラクタを追加
  Message(const Message& obj);
  Message(const char* _message);
  ~Message();

  void setMessage (const char* _message);
  char* getMessage (void);
};

std::istream &operator>>(std::istream& stream, Message& obj);
std::ostream &operator<<(std::ostream& stream, Message& obj);