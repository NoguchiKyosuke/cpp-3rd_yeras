#include <math.h>
#include "Circle.h"

#define M_PI 3.14159265358979323846

Circle::Circle () { // 引数を指定しない構築子 
    x = y = 0; rad = 10;
} 

Circle::Circle (int cx, int cy, int r) {  // 引数を指定する構築子
    x = cx; y = cy; rad = r; 
}

void Circle::setPosition (int x, int y) { 
    this->x = x; this->y = y; // this->x はメンバ変数の x であり，引数 x とは異なる変数！
}

void Circle::setRadius (int rad) { 
    this->rad = rad; // this->rad と rad は異なる変数！
}

// 追加。配列pに座標を代入する。
void Circle::getPosition (int xy[]) {
    xy[0] = x;
    xy[1] = y;
}

void Circle::getRadius (int N) {
    this->rad = sqrt(x*x + y*y - 2*x*y*cos(2*M_PI/N))/2;
}

void Circle::setRatio (double r) { // 内円の大きさの割合
    ratio = r/100.0;
}

// void Circle::draw (svg* svgObj, int N) {
//     this->N = N;
//     this->getRadius();
//     for (int i = 0; i < N; i++){
//         this->x = sin(i * 2 * M_PI /N) * 100 + 200;
//         this->y = cos(i * 2 * M_PI /N) * 100 + 200;
//         svgObj->drawCircle(this->x, this->y, this->rad);
//     }
// }