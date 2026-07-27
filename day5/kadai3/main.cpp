#include <iostream>
#include <string>
// 動的ロードで使用するライブラリ
#include <dlfcn.h>
// unique_ptrを使用するために必要なヘッダーファイル
#include <memory>
// クラスのインスタンスの生成時の関数の定義を含むヘッダーファイル
#include "plugin.hpp"

int main (int argc, char *argv[]) {
  // コマンドラインの引数が正しく指定されているかを確認する
  if(argc != 4){
    std::cerr << "Usage: " << argv[0] << " <library_path> <value1> <value2>" << std::endl;
    return 1;
  }

  // ライブラリのロード
  void* handle = dlopen(argv[1], RTLD_LAZY);
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
  double a = std::stod(argv[2]);
  double b = std::stod(argv[3]);

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

  return 0;
}
