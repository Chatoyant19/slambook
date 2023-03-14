// https://leetcode.cn/problems/integer-to-roman/
#include <iostream>
#include <string>
#include <algorithm>

std::string intToRoman(int& num);
std::string getRomanByI(const int& i, const int& tmp);

int main(int argc, char** argv) {
    int num;
    std::cin >> num;
    std::string res = intToRoman(num);
    // std::cout << "res is " << reverse(res.begin(), res.end()) << std::endl;
    // std::reverse();
    std::cout << res << std::endl;
    return 0;
}

std::string intToRoman(int& num) {
    int i = 0;
    int tmp;
    std::string res;
    while(num!=0) {
        tmp = num % 10;
        num = num / 10;
        std::string res_tmp = getRomanByI(i, tmp);
        res = res_tmp + res;;
        ++i;
    }
    return res;
}

std::string getRomanByI(const int& i, const int& tmp) {
    std::string res_tmp;
    if(i == 0) { //个位数
        if(tmp < 4) {
            for(int index = 0; index < tmp; ++index) {
                res_tmp += 'I';
            }
        }
        else if(tmp == 4) {
            res_tmp = "IV";
        }
        else if(tmp < 9) {
            res_tmp = 'V';
            for(int index = 0; index < tmp-5; ++index) {
                res_tmp += 'I';
            }
        }
        else { //=9
            res_tmp = "IX";
        }
    }
    else if(i == 1) { //十位数
        if(tmp < 4) {
            for(int index = 0; index < tmp; ++index) {
                res_tmp += 'X';
            }
        }
        else if(tmp == 4) {
            res_tmp = "XL";
        }
        else if(tmp < 9) {
            res_tmp = 'L';
            for(int index = 0; index < tmp-5; ++index) {
                res_tmp += 'X';
            }
        }
        else { //=9
            res_tmp = "LC";
        }
    }
    else if(i == 2) { //百位数
        if(tmp < 4) {
            for(int index = 0; index < tmp; ++index) {
                res_tmp += 'C';
            }
        }
        else if(tmp == 4) {
            res_tmp = "CD";
        }
        else if(tmp < 9) {
            res_tmp = 'D';
            for(int index = 0; index < tmp-5; ++index) {
                res_tmp += 'C';
            }
        }
        else { //=9
            res_tmp = "XM";
        }
    }
    else{ //>=千位数
        for(int index = 0; index < tmp; ++index) {
            res_tmp += "M";
        }
    }
    return res_tmp;
}