#pragma once

#include "ColorCircle.h"

class DoubleCircle : public ColorCircle {
private:
    std::string incolor; // 内円の描画色
    std::string outcolor; // 外円の描画色
public:
    DoubleCircle (); // 構築子
    DoubleCircle (int cx, int cy, int r, std::string inc, std::string outc); // 違う形式の構築子

    virtual void setColor (std::string c[]); // 色の設定
    virtual void draw (svg* svgObj); // Circle クラスの draw () の仮想関数
};