#include <iostream>
#include "ColorCircle.h"
#include "LineCircle.h"

int main() {
    svg *svgObj[1]; // SVGドキュメントを生成するオブジェクト
    ColorCircle colorcircle; // 円のオブジェクト
    LineCircle linecircle[2]; // 円のオブジェクト
    int posX = 100, posY = 100, width = 10, N = 4; // 円の描画位置
    std::string color, linecolor; // 円の色

    std::cout << "color of circle => ";
    std::cin >> color; // 円の色の入力

    std::cout << "number of circle => ";
    std::cin >> N; // 円の数の入力

    std::cout << "color of line => ";
    std::cin >> linecolor; // 線の色の入力

    std::cout << "width of between two lines => ";
    std::cin >> width; // 線の太さの入力

    colorcircle.setPosition(posX, posY); // 円の描画位置の指定
    colorcircle.setColor(color); // 円の色の指定
    linecircle[0].setPosition(posX, posY);
    linecircle[1].setPosition(posX, posY);
    linecircle[0].setColor(linecolor);
    linecircle[1].setColor(linecolor);
    linecircle[0].setWidth(width);
    linecircle[1].setWidth(width);

    svgObj[0] = new svg();

    svgObj[0]->open("circle.html", 640, 400); // ファイルを開く
    colorcircle.draw(svgObj[0], N); // 円の描画（svgObj のポインタを渡す）
    svgObj[0]->close(); // ファイルを閉じる
}
