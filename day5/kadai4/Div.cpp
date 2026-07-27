#ifndef __DIV_H__
#define __DIV_H__

#include "../plugin.hpp"
#include <string>
#include <memory>

// 抽象クラスPuginInterfaceを継承したDivクラスを定義
class Div: public PluginInterface{
    public:
        Div() {};
        ~Div() {};
        std::string getPluginName(void) override{
            return "Div";
        }
        double exec(double a, double b) override{
            return a / b;
        }
};

// C言語による記述で、C++のクラスを生成する関数を定義
extern "C" {
    // 新しいDivクラスのインスタンスを生成する関数
    std::unique_ptr<PluginInterface> new_instance(void) {
        return std::unique_ptr<PluginInterface>(new Div());
    }
}

#endif /* __DIV_H__ */