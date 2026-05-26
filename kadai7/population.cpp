#include <iostream>
#include <fstream>
#include "Population.h"
#include <string>

// Population.h 内で using namespace std; が記述されているので、std::の記述は全て省略されている！
void Population::read(const char *fileName) {
    ifstream ifs(fileName); // データファイル名を指定して開く
    if(ifs.fail()) { // データファイルの読み込みに失敗した場合
        cerr << "File do not exist."; // 名前が fileName のファイルが見つからなかった場合のエラー出力
        exit(0); // 強制終了
    }
    string str; // 分解前の文字列を一時保管する変数
    getline(ifs, str, '\r'); // 入力ストリームからの一行分の文字列を str に読み込む
    vector<string> labelStrs = split(str, ','); // 「,」を区切り文字とした文字列の分解
    for(unsigned long i=0; i < labelStrs.size(); i++) {
        labels.push_back(labelStrs.at(i)); // 文字列データ（業種名）代入する
    }
    getline(ifs, str, '\r'); // 入力ストリームからの一行分の文字列を str に読み込む
    vector<string> valueStrs = split(str, ','); // 「,」を区切り文字とした文字列の分解
    for(unsigned long i=0; i < valueStrs.size(); i++) {
        values.push_back(atoi(valueStrs.at(i).c_str())); // 数値データ（就業人口）を代入する。atoi は文字列を整数値に変換する標準関数
    }
}

vector<string> Population::split(string& str, char delim) { // delim を区切り文字とした文字列の分解。引数の文字列 str は参照で渡される
    vector<string> res;
    size_t current = 0, found;
    while((found = str.find_first_of(delim, current)) != string::npos){
        res.push_back(string(str, current, found - current));
        current = found + 1;
    }
    res.push_back(string(str, current, str.size() - current));
    return res;
}