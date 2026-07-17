#include <iostream>
#include <string>
// 動的ロードで使用するライブラリ
#include <dlfcn.h>

int main (int argc, char *argv[]) {
  // コマンドラインの引数が正しく指定されているかを確認する
  if(argc != 2){
    std::cerr << "Usage: " << argv[0] << " <library_path>" << std::endl;
    return 1;
  }

  // ライブラリのロード
  void* handle = dlopen(argv[1], RTLD_LAZY);
  // ライブラリが正しくロードされない場合のエラー処理
  if (!handle) {
    std::cerr << "Failed to load library: " << dlerror() << std::endl;
    return 1;
  }

  // 関数addとsubのポインタを取得
  auto add_func = reinterpret_cast<double(*)(double, double)>(dlsym(handle, "my_add"));
  auto sub_func = reinterpret_cast<double(*)(double, double)>(dlsym(handle, "my_sub"));
  // 関数が正しく取得されない場合のエラー処理
  if (!add_func || !sub_func) {
    std::cerr << "Failed to load functions: " << dlerror() << std::endl;
    dlclose(handle);
    return 1;
  }

  // 関数を使用して計算を行う
  double a = add_func(10, 20);
  std::cout << "add(10, 20) = " << a << std::endl;
  double b = sub_func(10, 20);
  std::cout << "sub(10, 20) = " << b << std::endl;

  // dlcloseでライブラリを閉じる
  dlclose(handle);

  return 0;
}
