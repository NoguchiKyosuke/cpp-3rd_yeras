/*
描画のサンプルプログラム
*/
#include <iostream>
#include <string>
#include "svg.h"

int main() {
    svg svgObj; // SVGドキュメントを生成するオブジェクト
    std::string name;
    
    std::cout << "What is your name? "; // 画面にメッセージ出力
    std::cin >> name; // 文字列の入力
    std::cout << "Hello, " << name <<"!"; // 画面にメッセージ出力
    
    svgObj.open("drawing.svg", 500, 600); // ファイルを開く
    svgObj.drawCircle(100, 100, 20, "red", 5);
    svgObj.drawCircle(100, 200, 20, "red");
    svgObj.drawRect(100, 300, 20, 40, "green", 5);
    svgObj.drawRect(100, 400, 20, 40, "green");
    svgObj.drawText(100, 500, "drawText");
    svgObj.close(); // ファイルを閉じる
}