#include <iostream>
#include "Circle.h"

int main() {
    svg svgObj; // SVGドキュメントを生成するオブジェクト
    Circle circle; // 円のオブジェクト
    // int posX, posY, radius; // 円の描画位置と半径
    int N; // 円の数
    
    std::cout << "number of circle => ";
    std::cin >> N; //円の数の入力
    
    // circle.setPosition(posX, posY); // 円の描画位置の指定
    // circle.setRadius(radius); // 円の半径の指定
    
    svgObj.open("circle.html", 640, 400); // ファイルを開く
    circle.draw(&svgObj, N); // 円の描画（svgObj のポインタを渡す）
    svgObj.close(); // ファイルを閉じる
}
