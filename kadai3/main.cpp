#include <iostream>
#include "Circle.h"

int main() {
    svg *svgObj[1]; // SVGドキュメントを生成するオブジェクト
    Circle circle; // 円のオブジェクト
    int posX = 100, posY = 100; // 円の描画位置
    int N; // 円の数

    std::cout << "number of circle => ";
    std::cin >> N; //円の数の入力
    
    circle.setPosition(posX, posY); // 円の描画位置の指定
    
    svgObj[0] = new svg();

    svgObj[0]->open("circle.html", 640, 400); // ファイルを開く
    circle.draw(svgObj[0], N); // 円の描画（svgObj のポインタを渡す）
    svgObj[0]->close(); // ファイルを閉じる
}
