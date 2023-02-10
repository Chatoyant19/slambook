// Copyright 2023 All Rights Reserved.
// Author: Wang Dan

/***********************************************************
 * purpose: check valid kuohao
 *
 * pipeline:
 *     1.遍历输入的字符串，如果是左括号，入栈。如果是右括号，首先判断当前栈中是否有元素，没有说明没有对应的左括号，直接返回false。然后判断栈顶元素是否和当前右括号匹配，如果匹配，则出栈，继续往下遍历，否则直接返回false.直到遍历完成，如果栈中还有元素说明左右括号对不上，也是返回false.
 *
 * usage:
 *    cmake ..
 *    make -j
 *    ./valid_kuohao
 **********************************************************/
#include <iostream>
#include <string>
#include <stack>

bool is_valid_kuohao(const std::string& input_str);

int main(int argc, char** argv) {
  std::string input_str;
  std::cin >> input_str;
  std::cout << "input string is: " << input_str << std::endl;

  if(input_str.size() == 0) {
    std::cout << "invalid input." << std::endl;
  }

  if(is_valid_kuohao(input_str)) {
    std::cout << "valid kuohao!" << std::endl;
  }
  else {
    std::cout << "invalid kuohao!" << std::endl;
  }
  return 0;
}

bool is_valid_kuohao(const std::string& input_str) {
  std::stack<char> ss;

  for (int i = 0; i < input_str.size(); ++i) {
    if((input_str[i] == '{') || (input_str[i] == '[') || (input_str[i] == '(')) {
      ss.push(input_str[i]);
    }
    else if((input_str[i] == '}') || (input_str[i] == ']') || (input_str[i] == ')')) {
      if(ss.empty()) {
        return false;
      }
      
      if((input_str[i] == '}') && (ss.top() != '{')) {
        return false;
      }
      else if((input_str[i] == ']') && (ss.top() != '[')) {
        return false;
      }
      else if((input_str[i] == ')') && (ss.top() != '(')) {
        return false;
      }

      // 程序能运行到这里，说明当前的括号是能匹配的
      ss.pop();
    }
    else { //考虑非法输入
      std::cout << "invalid input." << std::endl;
    }
  }

  if(!ss.empty()) {
    return false;
  }
  return true;
}