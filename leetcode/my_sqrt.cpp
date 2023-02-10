// Copyright 2023 All Rights Reserved.
// Author: Wang Dan

/***********************************************************
 * purpose: sqrt
 *
 * pipeline:
 *
 * usage:
 *    cmake ..
 *    make -j
 *    ./my_sqrt
 **********************************************************/
#include <iostream>
#include <math.h>

void my_sqrt(const double& num, double& res);

int main(int argc, char** argv) {
  double num;
  std::cin >> num;

  // 边界条件
  if(num <= 0) {
    std::cout << "error input." << std::endl;
    return -1;
  }

  std::cout << "input num is " << num << std::endl;

  // to test
  double truth_res = sqrt(num);
  std::cout << "truth res is: " << truth_res << std::endl;

  // my function
  double res;
  my_sqrt(num, res);
  std::cout << "res is: " << res << std::endl;

  return 0;
}

// 二分法
void my_sqrt(const double& num, double& res) {
  double low = 0, high = num, mid = 0;
  double err = 100.0;
  // 科学计数法的表示: 1e6 = 1X10^6, 1e-6 = 1X10^{-6}
  while ((err < -(1e-6)) || (err > 1e-6)) {  // threshold
    mid = (low + high) / 2;

    err = mid * mid - num;
    if(err > 0) {
      high = mid;
    }
    // else if()
    else {
      low = mid;
    }
  }

  res = mid;
}