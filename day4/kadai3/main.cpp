#include <iostream>
#include <Eigen/Dense>
#include <random>

int main (int argc, char *argv[]) {
  // N, σの値を設定する。
  int N = std::atoi(argv[1]);
  double sigma = 1.0;

  // xとyの値をベクトルとして定義する。
  Eigen::VectorXd x(N);
  Eigen::VectorXd y(N);
  for (int i = 1; i <= N; i++){
    x(i - 1) = -10 + (20 / (N - 1)) * (i - 1);
    y(i - 1) = (3 * x(i - 1) + 4) / 2;
  }

  // 平均値, 分散、データ数をコマンドライン引数から取得
  double ave = 0;

  // シード値を1として、乱数生成器を初期化
  std::uint32_t seed = 1;
  std::mt19937 method(seed);

  // 正規分布の乱数生成器を初期化
  std::normal_distribution<double> dist(ave, sigma);

  // N個の乱数を生成してxとyに加える
  for (int i = 0; i < N; i++) {
    double noise = dist(method);
    x(i) += noise;
    y(i) += noise;
  }


  return 0;
}
