// todo
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>

template <typename T>
double findMedianSortedArrays_1(const std::vector<T>& vec1, const std::vector<T>& vec2);

int main(int argc, char** argv) {
  int m, n;
  std::cin >> m;
  std::cin >> n;
  std::vector<int> mvec(m, 0);
  std::vector<int> nvec(n, 0);

  std::srand((unsigned)time(NULL));
  for (int i = 0; i < m; ++i) {
    mvec[i] = (rand() % (100 - 0 + 1)) + 0;;
  }

  for (int i = 0; i < n; ++i) {
    nvec[i] = (rand() % (100 - 0 + 1)) + 0;;
  }

  sort(mvec.begin(), mvec.end());
  sort(nvec.begin(), nvec.end());

  std::cout << "mvec: ";
  for (int i = 0; i < mvec.size(); ++i) {
    std::cout << mvec[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "nvec: ";
  for (int i = 0; i < nvec.size(); ++i) {
    std::cout << nvec[i] << " ";
  }
  std::cout << std::endl;

  double median = findMedianSortedArrays_1(mvec, nvec);
  std::cout << "median is " << median << std::endl;

  return 0;
}

// T(n) = O(m+n)
template <typename T>
double findMedianSortedArrays_1(const std::vector<T>& vec1, const std::vector<T>& vec2) {
  int len_1 = vec1.size();
  int len_2 = vec2.size();
  std::vector<T> tmp_vec(len_1 + len_2, 0);

  int i = 0, j = 0, k= 0;
  while (i < len_1 && j < len_2) {
    if(vec1[i] <= vec2[j]) {
      tmp_vec[k++] = vec1[i];
      ++i;
    } else {
      tmp_vec[k++] = vec2[j];
      ++j;
    }
  }

  while(i < len_1) {
    tmp_vec[k++] = vec1[i];
    ++i;
  } 

  while(j < len_2) {
    tmp_vec[k++] = vec2[j];
    ++j;
  }

  std::cout << "tmp_vec: ";
  for (int i = 0; i < tmp_vec.size(); ++i) {
    std::cout << tmp_vec[i] << " ";
  }
  std::cout << std::endl;

  int tmp_len = tmp_vec.size();
  // if(tmp_len > 1) {
    double res = (tmp_len % 2 == 0)
      ? (tmp_vec[(tmp_len - 1) / 2] + tmp_vec[tmp_len / 2]) / 2:
    tmp_vec[tmp_len / 2];
  // }
  

  return res;
}

template <typename T>
double findMedianSortedArrays_2(std::vector<T>& vec1,  std::vector<T>& vec2 , k) {
  static int rm_len = 0;
  // int k = (vec1.size() + vec2.size()) / 2 - rm_len;
  int k = k - rm_len;
  if (k == 0) return (std::min(vec1[0], vec2[0]));
  if (vec1[k / 2 - 1] <= vec2[k / 2 - 1]) {
    // 删除vec1中从0-(k/2-1)的元素
    int vec1_cnt = 0;
    for (std::vector<T>::iterator it = vec1.begin(); it != vec1.end();) {
      if(vec1_cnt < k/2) {
        it = vec1.erase(*it);
        // ++it;  
      }
      else {
        break;
      }
      ++vec1_cnt;
    }
    rm_len = vec1_cnt;
    findMedianSortedArrays_2(vec1, vec2);
  } else {
    // 删除vec2中从0-(k/2-1)的元素
    int vec2_cnt = 0;
    for (std::vector<T>::iterator it = vec2.begin(); it != vec2.end();) {
      if(vec2_cnt < k/2) {
        it = vec2.erase(*it);
        // ++it;  
      }
      else {
        break;
      }
      ++vec2_cnt;
    }
    rm_len = vec2_cnt;
    findMedianSortedArrays_2(vec1, vec2);
  }