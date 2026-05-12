#pragma once

#include "ColorCircle.h"

class DoubleCircle : public ColorCircle {
private:
    std::string incolor; // 内円の描画色
    std::string outcolor; // 外円の描画色
    double ratio;
public:
    DoubleCircle (); // 構築子
    DoubleCircle (int cx, int cy, int r, std::string inc, std::string outc); // 違う形式の構築子

    void draw (svg* svgObj); // Circle クラスの draw () を上書き（オーバーライド）する
    void setColor (std::string outc, std::string inc); // 色の設定
    void setRatio (double r); // 内円の大きさの割合
};