#pragma once

#include <vector>
#include <string>

using namespace std; // std:: の記述を省略するための記述

class Population {
private:
	vector<string> labels; // 項目の名前（業種名）を配列で保存
	vector<float> values; // 項目の値（就業人口）を配列で保存
	vector<string> split(string& str, char delim); // クラスの内部でのみ使用する関数
public:
	void read(const char *fileName); // ファイルからデータを読み込むメンバ関数
	void operator % (const Population& p); // 2つのPopulationオブジェクトを比較して、就業人口の比率を取得する演算子%のオーバーロード
	void display(); // データを表示するメンバ関数
	int operator ! ();
	std::string operator ^ (int n);
};