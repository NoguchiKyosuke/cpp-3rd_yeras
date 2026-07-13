#include <iostream>
#include <Eigen/Dense>
#include <random>
#include <fstream>

int main (int argc, char *argv[]) {
  // N, σの値を設定する。
  int N = std::atoi(argv[1]);

  // xとyの値をベクトルとして定義する。
  Eigen::VectorXd x(N);
  Eigen::VectorXd y(N);
  for (int i = 1; i <= N; i++){
    x(i - 1) = -10.0 + (20.0 / (N - 1)) * (i - 1);
    y(i - 1) = (3.0 * x(i - 1) + 4.0) / 2.0;
  }

  // 正規分布の平均値を0.0、標準偏差を1.0として定義する。
  double ave = 0.0;
  double sigma = 1.0;

  // シード値を1として、乱数生成器を初期化
  std::uint32_t seed = 1;
  std::mt19937 method(seed);

  // 正規分布の乱数生成器を初期化
  std::normal_distribution<double> dist(ave, sigma);

  // N個の乱数を生成してxとyに加える
  Eigen::VectorXd noise_x(N);
  Eigen::VectorXd noise_y(N);
  std::ofstream file("data.txt");
  for (int i = 0; i < N; i++) {
    noise_x(i) = x(i) + dist(method);
    noise_y(i) = y(i) + dist(method);
    // x, y, noise_x, noise_yの順でdata.txtに出力する
    file << i+1 << " " << x(i) << " " << y(i) << " " << noise_x(i) << " " << noise_y(i) << std::endl;
  }

  // ファイルを閉じる
  file.close();

  return 0;
}
