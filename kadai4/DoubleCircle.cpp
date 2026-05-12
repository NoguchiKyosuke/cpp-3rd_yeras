#include <math.h>
#include "DoubleCircle.h"

#define M_PI 3.14159265358979323846

DoubleCircle::DoubleCircle () : ColorCircle () { // 構築子
    incolor = "black";
    outcolor = "black";
}

DoubleCircle::DoubleCircle (int cx, int cy, int r, std::string inc, std::string outc) : ColorCircle (cx, cy, r, "") { // 属性を指定する構築子
     incolor = inc;
     outcolor = outc;
}

void DoubleCircle::draw (svg* svgObj) { // Circle クラスの draw () を上書き（オーバーライド）する
    svgObj->drawCircle(this->x, this->y, this->rad, incolor);
    svgObj->drawCircle(this->x, this->y, this->rad*ratio, outcolor);
} 

void DoubleCircle::setColor (std::string c[]) { // 色の設定
    incolor = c[1];
    outcolor = c[0];
}