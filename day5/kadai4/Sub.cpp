#ifndef __SUB_H__
#define __SUB_H__

#include "../plugin.hpp"
#include <string>
#include <memory>

// 抽象クラスPuginInterfaceを継承したSubクラスを定義
class Sub: public PluginInterface{
    public:
        Sub() {};
        ~Sub() {};
        std::string getPluginName(void) override{
            return "Sub";
        }
        double exec(double a, double b) override{
            return a - b;
        }
};

// C言語による記述で、C++のクラスを生成する関数を定義
extern "C" {
    // 新しいSubクラスのインスタンスを生成する関数
    std::unique_ptr<PluginInterface> new_instance(void) {
        return std::unique_ptr<PluginInterface>(new Sub());
    }
}

#endif /* __SUB_H__ */