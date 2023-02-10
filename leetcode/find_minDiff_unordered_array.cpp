// Copyright 2023 All Rights Reserved.
// Author: Wang Dan

/***********************************************************
 * describer:
 *
 * pipeline:
 *    1. 穷举法
 *    2. (1)先找到min和max（任何两个数的差值一定小于等于max-min）
 *       (2)如果当前值小于等于(min+max)/2=>val-min <=
 *        max-val,说明我们要找的符合要求的两个数的差值在[min,
 *        val],令max=val;如果当前值大于(min+max)/2=>val-min >
 *        max-val,说明我们要找的符合要求的两个数的差值在[val,
 *        max],令min=val;如果val<min或者val>max,continue.
 *    corner_case: vec.size() = 0/1;
 *
 * usage:
 *    cmake ..
 *    make -j
 *    ./find_minDiff_unordered_array
 **********************************************************/
#include <iostream>
#include <math.h>
#include <vector>
#include <climits>

template <typename T>
T find2NumIsMinDiff_1(const std::vector<T>& vec);

template <typename T>
T find2NumIsMinDiff_2(const std::vector<T>& vec);

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  int num;
  std::vector<int> vec(N, 0);
  for (int i = 0; i < N; ++i) {
    std::cin >> num;
    vec[i] = num;
  }

  if (N <= 0 || N == 1) return -1;

  int res_1 = find2NumIsMinDiff_1(vec);
  int res_2 = find2NumIsMinDiff_2(vec);
  std::cout << "res_1: " << res_1 << " "
            << "res_2: " << res_2 << std::endl;

  return 0;
}

// T(n) = O(n^2)
template<typename T>
T find2NumIsMinDiff_1(const std::vector<T>& vec) {
  T min_diff = INT_MAX;
  for (int i = 0; i < vec.size()-1; ++i) {
    for (int j = i + 1; j < vec.size(); ++j) {
      T tmp = abs(vec[i] - vec[j]);
      if(tmp < min_diff) {
        min_diff = tmp;
      }
    }
  }
  return min_diff;
}

// T(n) = O(log(n))
template<typename T>
T find2NumIsMinDiff_2(const std::vector<T>& vec) {
  T min = vec[0];
  T max = vec[0];
  for (int i = 0; i < vec.size(); ++i) {
    if (vec[i] < min){ 
      min = vec[i];
    }
    if(vec[i] > max) {
      max = vec[i];
    }
  }

  std::cout << "check min and max: " << min << ", " << max << std::endl;

  for (int i = 0; i < vec.size(); ++i) {
    if (vec[i] <= min || vec[i] >= max) continue;
    else if(2 * vec[i] <= (min + max)) {
      max = vec[i];
    }
    else if(2 * vec[i] > (min + max)) {
      min = vec[i];
    }
  } 
  return (max - min);
}
