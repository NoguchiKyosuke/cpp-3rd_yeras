#include <iostream>
#include <string>
// 動的ロードで使用するライブラリ
#include <dlfcn.h>
// unique_ptrを使用するために必要なヘッダーファイル
#include <memory>
// クラスのインスタンスの生成時の関数の定義を含むヘッダーファイル
#include "plugin.hpp"
#include <dirent.h>
#include <vector>
// strcmpを使用するために必要なヘッダーファイル
#include <cstring>

int main (int argc, char *argv[]) {
  // コマンドラインの引数が正しく指定されているかを確認する
  if(argc != 3){
    std::cerr << "Usage: " << argv[0] << " <value1> <value2>" << std::endl;
    return 1;
  }

  // コマンドライン引数で指定されたディレクトリを開く
  DIR* dir = opendir("plugin");
  struct dirent* file;
  std::vector<std::string> fileNames;
  while((file = readdir(dir)) != nullptr){
    // 特殊なファイル名"."と".."を除外して、ディレクトリ内のファイル名をvectorに格納する
    if(strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0){
        fileNames.push_back(file->d_name);
    }
  }

  // ディレクトリを閉じる
  closedir(dir);

  // vectorに格納されたファイル名のライブラリのすべてをロードして、計算を行う
  for(const auto& name : fileNames){
    std::string libPath = "plugin/" + name;
    void* handle = dlopen(libPath.c_str(), RTLD_LAZY);
    // ライブラリが正しくロードされない場合のエラー処理
    if (!handle) {
      std::cerr << "Failed to load library: " << dlerror() << std::endl;
      return 1;
    }

    // クラスのインスタンスを生成するための関数ポインタを取得
    auto new_instance = reinterpret_cast<std::unique_ptr<PluginInterface>(*)()>(dlsym(handle, "new_instance"));

    // 関数が正しく取得されない場合のエラー処理
    if (!new_instance) {
      std::cerr << "Failed to load function: " << dlerror() << std::endl;
      dlclose(handle);
      return 1;
    }

    // クラスのインスタンスを生成
    auto instance = new_instance();

    // コマンドライン引数から値を取得
    double a = std::stod(argv[1]);
    double b = std::stod(argv[2]);

    // getPluginName関数を呼び出してプラグイン名を取得
    std::string pluginName = instance->getPluginName();
    std::cout << "Loaded plugin: " << pluginName << std::endl;

    // exec関数を呼び出して計算を行う
    double result = instance->exec(a, b);
    std::cout << pluginName << "(" << a << ", " << b << ") = " << result << std::endl;

    // unique_ptrのリセット
    // これが無いと、segmentation faultが発生する
    instance.reset();

    // dlcloseでライブラリを閉じる
    dlclose(handle);
  }

  return 0;
}
