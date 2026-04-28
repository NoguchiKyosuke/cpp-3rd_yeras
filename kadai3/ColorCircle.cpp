#include <math.h>
#include "ColorCircle.h"

#define M_PI 3.14159265358979323846

ColorCircle::ColorCircle () : Circle () { // 構築子
    color = "black";
}

ColorCircle::ColorCircle (int cx, int cy, int r, std::string c) : Circle (cx, cy, r) { // 属性を指定する構築子
     color = c;
}

void ColorCircle::draw (svg* svgObj, int N) { // Circle クラスの draw () を上書き（オーバーライド）する
    this->N = N;
    this->getRadius();
    for (int i = 0; i < N; i++){
        this->x = sin(i * 2 * M_PI /N) * 100 + 200;
        this->y = cos(i * 2 * M_PI /N) * 100 + 200;
        svgObj->drawCircle(this->x, this->y, this->rad, this->color);
    }
} 

void ColorCircle::setColor (std::string c) { // 色の設定
    color = c;
}