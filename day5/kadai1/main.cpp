#include <iostream>
// ディレクトリの操作で使用するヘッダファイルを読み込む
#include <dirent.h>
#include <string.h>
#include <string>
#include <vector>

int main (int argc, char *argv[]) {
  // コマンドラインの引数が正しく指定されているかを確認する
  if(argc != 2){
    std::cerr << "Usage: " << argv[0] << " <directory_path>" << std::endl;
    return 1;
  }

  // コマンドライン引数で指定されたディレクトリを開く
  DIR* dir = opendir(argv[1]);
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

  // vectorに格納されたファイル名を出力する
  for(const auto& name : fileNames){
    std::cout << name << std::endl;
  }

  return 0;
}
