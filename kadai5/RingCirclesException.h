#include <exception>
#include <string>

class RingCirclesException : public std::exception {
private:
    std::string e_msg; // エラーメッセージ
public:
    RingCirclesException (const std::string& msg) : e_msg(msg) {} // エラーメッセージを引数にとる構築子
    void print() const { // エラーメッセージを出力する関数
        std::cerr << e_msg << std::endl;
    }
};