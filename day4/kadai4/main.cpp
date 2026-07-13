#include <iostream>
#include <Eigen/Dense>
#include <fstream>
#include <vector>

int main (int argc, char *argv[]) {
  // 読み込みモードでファイルを開く
  std::ifstream file("data.txt");
  // ファイルを開けなかった際のエラー処理
  if (!file.is_open()) {
    std::cerr << "ファイルを開くことができませんでした。" << std::endl;
    return 1;
  }

  // データを格納するベクトルを定義
  std::vector<double> x, y, noise_x, noise_y;

  int index;
  double val_x, val_y, noise_val_x, noise_val_y;
  while (file >> index >> val_x >> val_y >> noise_val_x >> noise_val_y) {
    x.push_back(val_x);
    y.push_back(val_y);
    noise_x.push_back(noise_val_x);
    noise_y.push_back(noise_val_y);
  }
  
  // ファイルを閉じる
  file.close();

  // 最小二乗法の正規方程式で使用する行列XとベクトルYを定義
  Eigen::MatrixXd A(2, 2);
  Eigen::VectorXd b(2);
  // 行列とベクトルを0で初期化する
  A.setZero();
  b.setZero();

  // 行列Aに値を代入する。
  for (int i = 0; i < x.size(); i++) {
    A(0, 0) += x[i] * x[i];
    A(0, 1) += x[i];
    A(1, 0) += x[i];
    A(1, 1) += 1;
    b(0) += x[i] * y[i];
    b(1) += y[i];
  }

  // 正規方程式を解く
  Eigen::VectorXd ans(2);
  ans = A.inverse() * b;

  // 結果を出力する
  std::cout << "直線データにおける最小二乗法の結果" << std::endl;
  std::cout << "傾き: " << ans(0) << std::endl;
  std::cout << "切片: " << ans(1) << std::endl;
  std::cout << "近似直線: y = " << ans(0) << " * x + " << ans(1) << std::endl;


  // ノイズデータにおいて、近似直線の値を計算する
  // 最小二乗法の正規方程式で使用する行列XとベクトルYを定義
  Eigen::MatrixXd noise_A(2, 2);
  Eigen::VectorXd noise_b(2);
  // 行列とベクトルを0で初期化する
  noise_A.setZero();
  noise_b.setZero();

  // 行列Aに値を代入する。
  for (int i = 0; i < noise_x.size(); i++) {
    noise_A(0, 0) += noise_x[i] * noise_x[i];
    noise_A(0, 1) += noise_x[i];
    noise_A(1, 0) += noise_x[i];
    noise_b(0) += noise_x[i] * noise_y[i];
    noise_b(1) += noise_y[i];
  }
  noise_A(1, 1) = 1;

  // 正規方程式を解く
  Eigen::VectorXd noise_ans(2);
  noise_ans = noise_A.inverse() * noise_b;

  // 結果を出力する
  std::cout << "ノイズデータにおける最小二乗法の結果" << std::endl;
  std::cout << "傾き: " << noise_ans(0) << std::endl;
  std::cout << "切片: " << noise_ans(1) << std::endl;
  std::cout << "近似直線: y = " << noise_ans(0) << " * x + " << noise_ans(1) << std::endl;

  return 0;
}
