#include <iostream>
#include <bits/stdc++.h>
#include "Population.h"


int main(int args, char* argv[]) {
    Population *pop[2]; // Populationのオブジェクト

    pop[0] = new Population();
    pop[1] = new Population();

    pop[0]->read("Aichi.txt"); // データファイルからデータを読み込む
    pop[1]->read("Zenkoku.txt"); // データファイルからデータを読み込む
    *pop[0] % *pop[1]; // 2つのPopulationオブジェクトを比較して、就業人口の比率を取得する。比較演算子%はPopulationクラスで定義されている。
    // pop[0]->display(); // 就業人口の比率を出力する(デバッグ用)
    int maxN = ! *pop[0]; // 就業人口の最大値を取得する
    std::string maxLabel = *pop[0] ^ maxN;
    std::cout << maxLabel << std::endl;
}
