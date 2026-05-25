#include <math.h>
#include "ColorCircle.h"

#define M_PI 3.14159265358979323846

ColorCircle::ColorCircle () : Circle () { // 構築子
    color = "black";
}

ColorCircle::ColorCircle (int cx, int cy, int r, std::string c) : Circle (cx, cy, r) { // 属性を指定する構築子
     color = c;
}

void ColorCircle::setColor (std::string c[]) { // 色の設定
    color = c[0];
}

void ColorCircle::draw (svg* svgObj) { // Circle クラスの draw () を上書き（オーバーライド）する
    svgObj->drawCircle(x, y, rad, color);
} 