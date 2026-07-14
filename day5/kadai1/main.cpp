#include <iostream>
// ディレクトリの操作で使用するヘッダファイルを読み込む
#include <dirent.h>
#include <string.h>

int main (int argc, char *argv[]) {
  // コマンドラインの引数が正しく指定されているかを確認する
  if(argc != 2){
    std::cerr << "Usage: " << argv[0] << " <directory_path>" << std::endl;
    return 1;
  }

  // コマンドライン引数で指定されたディレクトリを開く
  DIR* dir = opendir(argv[1]);
  struct dirent* file;
  while((file = readdir(dir)) != nullptr){
    // 特殊なファイル名"."と".."を除外して、ディレクトリ内のファイル名を出力する
    if(strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0){
        std::cout << file->d_name << std::endl;
    }
  }

  return 0;
}
