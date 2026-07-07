#include <iostream>
#include <Eigen/Dense>
#include <random>

int main (int argc, char *argv[]) {
  // 平均値0, 分散1として定義
  double average = 0.0;
  double variance = 1.0;
  int N[] = {10, 100, 1000, 10000, 100000};

  std::random_device rd;
  std::uint32_t seed = rd();
  std::mt19937 method(seed);

  std::normal_distribution<double> dist(average, variance);

  double val = dist(method);

  printf("平均値: %f, 分散: %f, N: %d, 乱数: %f\n", average, variance, N[0], val);

  return 0;
}
