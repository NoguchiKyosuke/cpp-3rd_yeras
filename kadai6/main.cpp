#include <iostream>
#include <bits/stdc++.h>
#include "Population.h"


int main(int args, char* argv[]) {
    svg *svgObj; // SVGドキュメントを生成するオブジェクト
    Population *pop; // Populationのオブジェクト

    pop = new Population();

    pop->read("Aichi.txt"); // データファイルからデータを読み込む
    
    svgObj = new svg();

    svgObj->open("circle.html", 1280, 400); // ファイルを開く

    pop->drawgraph(svgObj); // SVGドキュメントにグラフを描画する

    svgObj->close(); // ファイルを閉じる
}
