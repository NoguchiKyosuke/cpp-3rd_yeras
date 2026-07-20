#ifndef __MUL_H__
#define __MUL_H__

#include "../plugin.hpp"
#include <string>
#include <memory>

// 抽象クラスPuginInterfaceを継承したMulクラスを定義
class Mul: public PluginInterface{
    public:
        Mul() {};
        ~Mul() {};
        std::string getPluginName(void) override{
            return "Mul";
        }
        double exec(double a, double b) override{
            return a * b;
        }
};

// C言語による記述で、C++のクラスを生成する関数を定義
extern "C" {
    // 新しいMulクラスのインスタンスを生成する関数
    std::unique_ptr<PluginInterface> new_instance(void) {
        return std::unique_ptr<PluginInterface>(new Mul());
    }
}

#endif /* __MUL_H__ */