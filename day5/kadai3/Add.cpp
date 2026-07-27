#ifndef __ADD_H__
#define __ADD_H__

#include "plugin.hpp"
#include <string>
#include <memory>

// 抽象クラスPuginInterfaceを継承したAddクラスを定義
class Add: public PluginInterface{
    public:
        Add() {};
        ~Add() {};
        std::string getPluginName(void) override{
            return "Add";
        }
        double exec(double a, double b) override{
            return a + b;
        }
};

// C言語による記述で、C++のクラスを生成する関数を定義
extern "C" {
    // 新しいAddクラスのインスタンスを生成する関数
    std::unique_ptr<PluginInterface> new_instance(void) {
        return std::unique_ptr<PluginInterface>(new Add());
    }
}

#endif /* __ADD_H__ */