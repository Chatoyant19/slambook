// Copyright 2023 All Rights Reserved.
// Author: Wang Dan

/***********************************************************
 * purpose: sort,ref: https://www.cnblogs.com/BobHuang/p/11263183.html
 *
 * describer:
 * 1. 冒泡排序，稳定
 *
 *
 * usage:
 *    cmake ..
 *    make -j
 *    ./find_minDiff_unordered_array
 **********************************************************/
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

template <typename T>
void bubbleSort(std::vector<T>& vec);

template<typename T>
void selectionSort(std::vector<T>& vec);

template<typename T>
void insertSort(std::vector<T>& vec);

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  int num;
  std::vector<int> vec(N, 0);
  std::srand((unsigned)time(NULL));
  for (int i = 0; i < N; ++i) {
    // std::cin >> num;
    // vec[i] = rand();
    // vec[i] = (rand() % (100 - 0)) + 0; // return int value in [0,100)
    // vec[i] = (rand() % (100 - 0 + 1)) + 0; // return int value in [0,100]
    vec[i] = (rand() % (100 - 0)) + 0 + 1; // return int value in (0,100)
  }

  std::cout << "init vec: " << std::endl;
  for (int i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;

  bubbleSort(vec);

  std::cout << "after bubble sort, vec: " << std::endl;
  for (int i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;

  selectionSort(vec);

  std::cout << "after selection sort, vec: " << std::endl;
  for (int i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;

  insertSort(vec);

  std::cout << "after insert sort, vec: " << std::endl;
  for (int i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}

// T(n) = O(n)
template<typename T>
void bubbleSort(std::vector<T>& vec) {
  for (int i = 1; i < vec.size(); ++i) {
    for (int j = 0; j < vec.size() - i; ++j) {
      if(vec[j] > vec[j+1]) {
        // T tmp = vec[j];
        // vec[j] = vec[j+1];
        // vec[j + 1] = tmp;

        std::swap(vec[j], vec[j+1]);
      }
    } 
  }
}

template<typename T>
void selectionSort(std::vector<T>& vec) {
  for(int i = 0; i < vec.size()-1; ++i) {
    int min_tag = i;
    for(int j = i+1; j < vec.size(); ++j) {
      if(vec[j] < vec[min_tag]) {
        min_tag = j;
      }
    }
    std::swap(vec[i], vec[min_tag]);
  }
}

template<typename T>
void insertSort(std::vector<T>& vec) {
  for(int i = 1; i < vec.size(); ++i) {
    T tmp = vec[i];
    for(int j = i-1; j >=0; j--) { 
      std::cout << "wd..3" << std::endl;
      if(tmp < vec[j]) {
        vec[j+1] = vec[j];
      }
      else {
        vec[++j] = tmp;
        break;
      }
    }

  }
}