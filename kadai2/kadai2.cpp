#include "Circle.h"

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

int Circle::getRadius () {
    return rad;
}

void Circle::draw (svg* svgObj, int N) {
    this->N = N;
    this->x = 10;
    this->y = 10;
    this->rad = 10;
    for (int i = 0; i < N; i++){
        svgObj->drawCircle(x, y, rad);
        x += 20;
        y += 20;
    }
}
