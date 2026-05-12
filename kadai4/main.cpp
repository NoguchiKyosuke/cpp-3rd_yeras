#include <iostream>
#include <bits/stdc++.h>
#include "ColorCircle.h"
#include "DoubleCircle.h"

#define M_PI 3.14159265358979323846
#define POSX 100
#define POSY 100

int main(int args, char* argv[]) {
    svg *svgObj[1]; // SVGドキュメントを生成するオブジェクト
    ColorCircle *colorcircle; // 円のオブジェクト
    DoubleCircle *doublecircle; // 輪郭のオブジェクト

    int N; // 円の個数
    double ratio; // 内円の大きさの割合
    std::string color[3], linecolor; // 円の色、輪郭の色

    N = atoi(argv[1]); // 円の個数
    color[0] = argv[2]; // ColorCircleの色
    color[1] = argv[3]; // 外円の色
    color[2] = argv[4]; // 内円の色
    ratio = atof(argv[5]); // 割合

    colorcircle = new ColorCircle();
    doublecircle = new DoubleCircle();

    colorcircle->setPosition(POSX, POSY); // 円の描画位置の指定
    colorcircle->setColor(color[0]); // 円の色の指定
    doublecircle->setPosition(POSX, POSY); // 輪郭の描画位置の指定
    doublecircle->setColor(color[1], color[2]); // 輪郭の色の指定
    doublecircle->setRatio(ratio); // 内円の大きさの割合の指定

    svgObj[0] = new svg();

    svgObj[0]->open("circle.html", 640, 400); // ファイルを開く
    // colorcircle->draw(svgObj[0], N); // 円の描画（svgObj のポインタを渡す）
    doublecircle->draw(svgObj[0]); // 二重円の描画（svgObj のポインタを渡す）
    svgObj[0]->close(); // ファイルを閉じる
}
