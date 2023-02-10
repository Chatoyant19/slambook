// Copyright 2023 All Rights Reserved.
// Author: Wang Dan

/***********************************************************
 * describer: 有N个石头，被依次编号为0,1,…,N-1。已知这N个石头的重量，找到其中重量相差为D的两个石头
 *            Q1:如果找到一对就返回编号
 *            Q2:要求时间复杂度和空间复杂度都为O(n)
 *            Q3:返回所有符合要求的stone pairs, 且时间复杂度不大于O(N*M)(M是返回结果pairs的数量)            
 * 
 *
 * usage:
 *    cmake ..
 *    make -j
 *    ./find_stone_pair
 **********************************************************/

#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>

bool findApairDiffIsD_1(const std::vector<double>& w_vec,
                        const double& D, std::vector<int>& res);
bool findApairDiffIsD_2(std::unordered_map<int, double>& w_map,
                        const double& D, std::vector<int>& res);
bool findAllPairsDiffIsD(std::unordered_multimap<int, double>& w_multimap,
                         const double& D, std::vector<std::vector<int>>& res);

int main(int argc, char** argv) {
  // number of stones
  int N;
  std::cin >> N;
  // weight of stones
  double W;
  
  /*
  // 直接遍历
  std::vector<double> w_vec(N, 0);
  for (int i = 0; i < N; ++i) {
    std::cin >> W;
    w_vec[i] = W;
  }
  // // for(auto w: N) {
  // //   std::cin >> W;
  // // }

  // weight difference
  double D;
  std::cin >> D;

  std::vector<int> res_1;
  if (findApairDiffIsD_1(w_vec, D, res_1)) {
    std::cout << "print out a stone pair: " << res_1[0] << " " << res_1[1]
            << std::endl;
  } else {
    std::cout << "faild to matched stone pair" << std::endl;
  }
  */

 /*
  std::unordered_map<int, double> w_map;
  for (int i = 0; i < N; ++i) {
    std::cin >> W;
    // w_map.emplace(pair<double, int>(W, i));
    w_map.emplace(std::make_pair(W, i));
  }

  // check w_map
  std::unordered_map<int, double>::iterator w_iter;
  for (w_iter = w_map.begin(); w_iter != w_map.end(); ++w_iter) {
    std::cout << w_iter->first << " " << w_iter->second << std::endl;
  }

  // weight difference
  double D;
  std::cin >> D;

  std::vector<int> res_2;
  if (findApairDiffIsD_2(w_map, D, res_2)) {
    std::cout << "print out a stone pair: " << res_2[0] << " " << res_2[1]
            << std::endl;
  } else {
    std::cout << "faild to matched stone pair" << std::endl;
  }
  */


  std::unordered_multimap<int, double> w_multimap;
  for (int i = 0; i < N; ++i) {
    std::cin >> W;
    w_multimap.emplace(std::make_pair(W, i));
  }

  // check w_multimap
  std::unordered_multimap<int, double>::iterator w_iter;
  for (w_iter = w_multimap.begin(); w_iter != w_multimap.end(); ++w_iter) {
    std::cout << w_iter->first << " " << w_iter->second << std::endl;
  }

  // weight difference
  double D;
  std::cin >> D;

  std::vector<std::vector<int>> res_3;
  if (findAllPairsDiffIsD(w_multimap, D, res_3)) {
    for (int i = 0; i < res_3.size(); ++i){
      std::cout << "print out a stone pair: " << res_3[i][0] << " " << res_3[i][1]
                << std::endl;
    }
      
  }
  else {
    std::cout << "faild to matched stone pair" << std::endl;
  }

  return 0;
}

// T(n) = O(n^2)
// S(n) = O(１)
bool findApairDiffIsD_1(const std::vector<double>& w_vec, const double& D, 
                        std::vector<int>& res) {
  for (int i = 0; i < w_vec.size()-1; ++i) {
    for (int j = i + 1; j < w_vec.size(); ++j) {
      int w_temp = abs(w_vec[i] - w_vec[j]);
      if(w_temp == D) {
        res = {i, j};
        return true;
      }
    }
  }
  return false;
}

// 只适合无重复val(weight)的或者相同val(weight)只存储其中一个，确保能找到一对符合要求的stone pair
// 以空间(hash)换取时间
// T(n) = O(n)
// S(n) = O(n)
bool findApairDiffIsD_2(std::unordered_map<int, double>& w_map, const double& D, std::vector<int>& res) {
  std::unordered_map<int, double>::iterator w_iter;
  for (w_iter = w_map.begin(); w_iter != w_map.end(); ++w_iter) {
    double key_1 = w_iter->first;
    // std::cout << "check key: " << key_1 << std::endl;

    std::unordered_map<int, double>::iterator tmp_iter;
    // if(w_map.find(abs(key_1 - D)) != w_map.end()) { //!!, if not, find will return end()
    if(w_map.count(key_1 - D) != 0) { // found key_2!
      tmp_iter = w_map.find(key_1 - D);
      res = {w_iter->second, tmp_iter->second};
      return true;
    }
    else if(w_map.count(key_1 + D) != 0) {
      tmp_iter = w_map.find(key_1 + D);
      res = {w_iter->second, tmp_iter->second};
      return true;
    }
  }
  return false;
}

// 用unordered_multimap存储允许重复的key,同时也可以用hash结构进行快速查询
// 删除重复的stone pair
bool findAllPairsDiffIsD(std::unordered_multimap<int, double>& w_multimap, const double& D, std::vector<std::vector<int>>& res) {
  std::unordered_multimap<int, double>::iterator w_iter;
  for (w_iter = w_multimap.begin(); w_iter != w_multimap.end(); ++w_iter) {
    double key_1 = w_iter->first;
    // std::cout << "check key: " << key_1 << std::endl;

    std::unordered_multimap<int, double>::iterator tmp_iter;
    // if(w_multimap.find(abs(key_1 - D)) != w_multimap.end()) {
    
    if(w_multimap.count(key_1 - D) != 0) { // find key_2!
      tmp_iter = w_multimap.find(key_1 - D);
      std::vector<int> res_tmp = {w_iter->second, tmp_iter->second};
      // return true;
      res.emplace_back(res_tmp);
    }
    else if(w_multimap.count(key_1 + D) != 0) {
      tmp_iter = w_multimap.find(key_1 + D);
      std::vector<int> res_tmp = {w_iter->second, tmp_iter->second};
      // return true;
      res.emplace_back(res_tmp);
    }

    for (std::vector<std::vector<int>>::iterator vec_iter=res.begin(); vec_iter!=res.end();) {
      std::cout << (*vec_iter)[0] << " " << (*vec_iter)[1] << std::endl;
      if(((*vec_iter)[0] == res[res.size()-1][1]) && ((*vec_iter)[1] == res[res.size()-1][0])) {
        vec_iter = res.erase(vec_iter);
      }
      else {
        ++vec_iter;
      }
    }
  }

  if(res.size() > 0) {
    return true;
  }
  else {
    return false;
  }
}