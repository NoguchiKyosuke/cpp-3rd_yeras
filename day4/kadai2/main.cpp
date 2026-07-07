#include <iostream>
#include <Eigen/Dense>
#include <random>

int main (int argc, char *argv[]) {
  // ベクトルaとbを定義する。
  Eigen::VectorXd a(3);
  Eigen::VectorXd b(3);

  // ベクトルaとbに値を代入する。
  a << 1, 2, 3;
  b << 0, 1, 2;

  // ベクトルaとbの和を計算する。
  Eigen::VectorXd C = a + b;
  std::cout << "a + b = " << C.transpose() << std::endl;

  // ベクトルaとbのベクトル積を計算する。
  Eigen::MatrixXd D = a * b.transpose();
  std::cout << "a * b^T = " << std::endl << D.transpose() << std::endl;

  // ベクトルaとbの内積を計算する。
  double E = a.dot(b);
  std::cout << "a . b = " << E << std::endl;

  // 行列Aを定義する。
  Eigen::MatrixXd A(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = i + j;
    }
  }

  // 行列Aとベクトルaの積を計算する。
  Eigen::VectorXd F = A * a;
  std::cout << "A * a = " << F.transpose() << std::endl;

  // 行列Bを定義する。
  Eigen::MatrixXd B(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      B(i, j) = i * j;
    }
  }

  // 行列Aと行列Bの積を計算する。
  Eigen::MatrixXd G = A * B;
  std::cout << "A * B = " << std::endl << G << std::endl;


  return 0;
}
