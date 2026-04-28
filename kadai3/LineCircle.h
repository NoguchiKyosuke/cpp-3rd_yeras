#pragma once

#include "Circle.h"

class LineCircle : public Circle {
private:
    std::string color; // 描画色
    int width; // 線の太さ
public:
    LineCircle (); // 構築子
    LineCircle (int cx, int cy, int r, std::string c, int w); // 違う形式の構築子

    void draw (svg* svgObj); // Circle クラスの draw () を上書き（オーバーライド）する
    void setColor (std::string c); // 色の設定
    void setWidth (int w); // 線の太さの設定
};