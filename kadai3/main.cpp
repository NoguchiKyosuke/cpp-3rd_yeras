#include <iostream>
#include <bits/stdc++.h>
#include "ColorCircle.h"
#include "LineCircle.h"

#define M_PI 3.14159265358979323846
#define POSX 100
#define POSY 100

int main(int args, char* argv[]) {
    svg *svgObj[1]; // SVGドキュメントを生成するオブジェクト
    ColorCircle *colorcircle; // 円のオブジェクト
    LineCircle *linecircle[2]; // 輪郭のオブジェクト

    int width, N; // 輪郭の太さ、円の個数
    std::string color, linecolor; // 円の色、輪郭の色

    N = atoi(argv[1]); // 円の個数
    color = argv[2]; // 円の色
    linecolor = argv[3]; // 輪郭の色
    width = atoi(argv[4]); // 輪郭の太さ

    colorcircle = new ColorCircle();
    linecircle[0] = new LineCircle();
    linecircle[1] = new LineCircle();

    colorcircle->setPosition(POSX, POSY); // 円の描画位置の指定
    colorcircle->setColor(color); // 円の色の指定
    linecircle[0]->setPosition(POSX, POSY); // 輪郭の描画位置の指定
    linecircle[1]->setPosition(POSX, POSY);
    linecircle[0]->setColor(linecolor); // 輪郭の色の指定
    linecircle[1]->setColor(linecolor);
    linecircle[0]->setWidth(width); // 輪郭の太さの指定
    linecircle[1]->setWidth(width);
    linecircle[0]->setRadius(100 - sqrt(100*100 + 100*100 - 2*100*100*cos(2*M_PI/N))/2); // 輪郭の半径の指定
    linecircle[1]->setRadius(100 + sqrt(100*100 + 100*100 - 2*100*100*cos(2*M_PI/N))/2);

    svgObj[0] = new svg();

    svgObj[0]->open("circle.html", 640, 400); // ファイルを開く
    colorcircle->draw(svgObj[0], N); // 円の描画（svgObj のポインタを渡す）
    linecircle[0]->draw(svgObj[0]); // 輪郭の描画（svgObj のポインタを渡す）
    linecircle[1]->draw(svgObj[0]); // 輪郭の描画（svgObj のポインタを渡す）
    svgObj[0]->close(); // ファイルを閉じる
}
