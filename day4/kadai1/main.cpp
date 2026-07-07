#include <iostream>
#include <Eigen/Dense>
#include <random>

int main (int argc, char *argv[]) {
  // 平均値, 分散、データ数をコマンドライン引数から取得
  double ave = std::stod(argv[1]);
  double sd = std::stod(argv[2]);
  int N = std::atoi(argv[3]);

  // シード値を取得し、乱数生成器を初期化
  std::uint32_t seed = std::atoi(argv[4]);
  std::mt19937 method(seed);

  // 正規分布の乱数生成器を初期化
  std::normal_distribution<double> dist(ave, sd);

  // N個の乱数を生成して出力
  for (int i = 0; i < N; i++) {
    std::cout << dist(method) << std::endl;
  }

  return 0;
}
