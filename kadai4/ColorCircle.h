#pragma once

#include "Circle.h"

class ColorCircle : public Circle {
friend class DoubleCircle;
private:
    std::string color; // 描画色
public:
    ColorCircle (); // 構築子
    ColorCircle (int cx, int cy, int r, std::string c); // 違う形式の構築子

    virtual void setColor (std::string c[]); // 色の設定
    virtual void draw (svg* svgObj); // Circle クラスの draw () の仮想関数
};