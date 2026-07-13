#include <iostream>
#include <Eigen/Dense>
#include <random>
#include <fstream>

int main (int argc, char *argv[]) {
  // 平均値, 分散、データ数をコマンドライン引数から取得
  double ave = std::stod(argv[1]);
  double sd = std::stod(argv[2]);
  int N = std::atoi(argv[3]);

  // 標本平均の値を記述するファイル
  std::ofstream mean_file("s_mean.txt");
  // 標本分散の値を記述するファイル
  std::ofstream var_file("s_var.txt");

  for (int n = 10; n <= N; n = n*10) {
    // シード値を取得し、乱数生成器を初期化
    std::uint32_t seed = std::atoi(argv[4]);
    std::mt19937 method(seed);
    
    // 正規分布の乱数生成器を初期化
    std::normal_distribution<double> dist(ave, sd);
    
    // 乱数を格納するベクトルと合計値を格納する変数を定義
    std::vector<double> data(n);
    double sum = 0.0;
    
    // N個の乱数を生成して出力
    for (int i = 0; i < n; i++) {
      data[i] = dist(method);
      sum += data[i];
    }
  
    // 生成した乱数群の標本平均を計算
    double s_mean = sum / n;
    mean_file << n << " " << s_mean << std::endl;
  
    // 生成した乱数群の標本分散を計算
    double s_var = 0.0;
    for (int i = 0; i < n; i++) {
      s_var += (data[i] - s_mean) * (data[i] - s_mean);
    }
    s_var /= n;
    var_file << n << " " << s_var << std::endl;
  }

  // ファイルを閉じる
  mean_file.close();
  var_file.close();
  return 0;
}
