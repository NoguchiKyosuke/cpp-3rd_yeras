#include <iostream>
#include <bits/stdc++.h>
#include "Circle.h"
#include "ColorCircle.h"
#include "DoubleCircle.h"

#define M_PI 3.14159265358979323846
#define POSX 100
#define POSY 100

int main(int args, char* argv[]) {
    svg *svgObj[1]; // SVGドキュメントを生成するオブジェクト
    Circle **circleArray; // 円のオブジェクトの配列

    int N; // 円の個数
    double ratio; // 内円の大きさの割合
    std::string ccolor[1], dcolor[2], linecolor; // 円の色、輪郭の色

    N = atoi(argv[1]); // 円の個数
    ccolor[0] = argv[2]; // ColorCircleの色
    dcolor[0] = argv[3]; // 外円の色
    dcolor[1] = argv[4]; // 内円の色
    ratio = atof(argv[5]); // 割合

    circleArray = new Circle*[2];
    circleArray[0] = new ColorCircle();
    circleArray[1] = new DoubleCircle();
    circleArray[0]->setColor(ccolor); // 円の色の指定
    circleArray[1]->setColor(dcolor); // 輪郭の色の指定
    circleArray[1]->setRatio(ratio); // 内円の大きさの割合の指定
    circleArray[0]->setRadius(sqrt((100*100 + 100*100 - 2*100*100*cos(2*M_PI/N)))/2); // 円の半径の指定
    circleArray[1]->setRadius(sqrt((100*100 + 100*100 - 2*100*100*cos(2*M_PI/N)))/2); // 二重円の半径の指定


    svgObj[0] = new svg();


    svgObj[0]->open("circle.html", 640, 400); // ファイルを開く
    for (int i = 0; i < N; i++){
        int x = sin(i * 2 * M_PI /N) * 100 + 200;
        int y = cos(i * 2 * M_PI /N) * 100 + 200;
        if(i % 2 == 0){
            circleArray[0]->setPosition(x, y); // 円の描画位置の指
            circleArray[0]->draw(svgObj[0]); // 円の描画（svgObj のポインタを渡す）
        }else{
            circleArray[1]->setPosition(x, y); // 輪郭の描画位置の指定
            circleArray[1]->draw(svgObj[0]); // 二重円の描画（svgObj のポインタを渡す）
        }
    }
    svgObj[0]->close(); // ファイルを閉じる
}
