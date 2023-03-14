// https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
#include <iostream>
#include <vector>

bool findNumberIn2DArray(const std::vector<std::vector<int>>& matrix, const int& target);

int main(int argc, char** argv) {
    int N;
    std::cin >> N;
    // todo: vector的vector的初始化、定义、存值
    std::vector<std::vector<int>> matrix(N, std::vector<int>(N, 0));
    int num;
    for(int i = 0; i < N; ++i) {
        for(int j =0; j < N; ++j) {
            std::cin >> num;
            matrix[i][j] = num;
        }
    }

    int target;
    std::cin >> target;

    bool res = findNumberIn2DArray(matrix, target);
    if(res){
        std::cout << "true" << std::endl;
    }
    else {
        std::cout << "false" << std::endl;
    }

    return 0;
}

bool findNumberIn2DArray(const std::vector<std::vector<int>>& matrix, const int& target) {
    int i = 0, j = matrix[0].size()-1;
    while(i<matrix.size() && j >=0) {
        if(target == matrix[i][j]) {
            return true;
        }
        else if(target < matrix[i][j]){
            --j;
        }
        else { //target > matrix[i][j]
            ++i;
        }
    }
    return false;
}