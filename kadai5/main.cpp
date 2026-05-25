#include <iostream>
#include <bits/stdc++.h>
#include "RingCircles.h"
#include "ColorCircle.h"
#include "LineCircle.h"
#include "DoubleCircle.h"

#define M_PI 3.14159265358979323846
#define POSX 100
#define POSY 100
#define OFFSETX 300

int main(int args, char* argv[]) {
    int n = atoi(argv[1]); // 円の個数
    svg svgObj; // SVGドキュメントを生成するオブジェクト
    
    RingCircles<ColorCircle> cc; // 円環(ColorCircle)クラスの生成
    cc.setCircles(n); // 円の個数の指定
    cc.setPosition(POSX, POSY); // 描画位置の指定
    // RingCircles<LineCircle> lc; // 円環(LineCircle)クラスの生成
    // lc.setCircles(n); // 円の個数の指定
    // lc.setPosition(POSX+OFFSETX, POSY); // 描画位置の指定
    // RingCircles<DoubleCircle> dc; // 円環(DoubleCircle)クラスの生成
    // dc.setCircles(n); // 円の個数の指定
    // dc.setPosition(POSX+OFFSETX*2, POSY); // 描画位置の指定

    svgObj.open("circle.html", 1280, 400); // ファイルを開く
    cc.draw(&svgObj); // 円環(ColorCircle)の描画
    // lc.draw(&svgObj); // 円環(LineCircle)の描画
    // dc.draw(&svgObj); // 円環(DoubleCircle)の描画
    svgObj.close(); // ファイルを閉じる
}
