#include "LineCircle.h"

LineCircle::LineCircle () : Circle () { // 構築子
    color = "black";
    width = 1;
}

LineCircle::LineCircle (int cx, int cy, int r, std::string c, int w) : Circle (cx, cy, r) { // 属性を指定する構築子
     color = c;
     width = w;
}

void LineCircle::draw (svg* svgObj) { // Circle クラスの draw () を上書き（オーバーライド）する
    svgObj->drawCircle(x, y, rad, color, width);
} 

void LineCircle::setColor (std::string c) { // 色の設定
    color = c;
}

void LineCircle::setWidth (int w) {
    width = w;
}