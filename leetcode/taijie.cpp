// Copyright 2023 All Rights Reserved.
// Author: Wang Dan

/***********************************************************
 * describer: 跳台阶。
 * purpose: fibonacci
 *
 * pipeline:f(n) = f(n-1) + f(n-2)
 *
 * usage:
 *    cmake ..
 *    make -j
 *    ./my_sqrt
 **********************************************************/
#include <iostream>
#include <math.h>

int getFibonacci_1(const int& n);
int getFibonacci_2(const int& n);

int main(int argc, char** argv) {
  // input taijie number
  int n;
  std::cin >> n;
  std::cout << "taijie num: " << n << std::endl;

  if(n <= 0) {
    std::cout << "invalid input." << std::endl;
    return -1;
  }

  int res_1 = getFibonacci_1(n);
  std::cout << "total has " << res_1 << " methods." << std::endl;

  int res_2 = getFibonacci_2(n);
  std::cout << "total has " << res_2 << " methods." << std::endl;

  return 0;
}

// 跳台阶，一次可以跳１级也可以２级，如果跳n级总共有多少种方法。
int getFibonacci_1(const int& n) {
  if (n == 1) return 1;
  if (n == 2) return 2;

  if(n > 2) {
    return (getFibonacci_1(n - 1) + getFibonacci_1(n - 2));
  }
}

// 跳台阶，一次可以跳１级也可以n级，总共有多少种方法。
int getFibonacci_2(const int& n) { return (pow(2, n-1)); }