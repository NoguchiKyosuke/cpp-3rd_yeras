#pragma once

#include <stdio.h>
#include "svg.h"

class Circle { 
friend class ColorCircle;
friend class DoubleCircle;
private:
    int x, y;
    int rad;
    svg* svgObj;
    int N;
    double ratio;

public:
    Circle (); // 関数の内容は記述しない
    Circle (int cx, int cy, int r = 10);
    void setPosition (int x, int y);
    void setRadius (int rad);
    void getPosition (int xy[]); // 追加。配列pに座標を代入する。
    void getRadius (int N);
    virtual void setColor (std::string c[]) = 0; // 色の設定の仮想関数
    void setRatio (double r); // 内円の大きさの割合の仮想関数
    virtual void draw (svg* svgObj) = 0; // 純粋仮想関数
};
