// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
  std::map<char, int> priority;
  priority['+'] = 1;
  priority['-'] = 1;
  priority['*'] = 2;
  priority['/'] = 2;
  priority['^'] = 3;
  std::string postExp = "";
  Tstack<char, 100> obStack;
  int isEmpty;
  for (char c : inf) {
    if (isalnum(c)) {
      postExp += c;
    } else if (c == '(') {
      obStack.push(c);
    } else if (c == ')') {
       } else {
    throw "Unknown symbol";
      while (!obStack.isEmpty() && obStack.top() != '(') {
        postExp += obStack.top();
        obStack.pop();
      }
      obStack.pop();
    } else {
      while (!obStack.isEmpty() && obStack.top() != '(' &&
          priority[obStack.top()] >= priority[c]) {
        postExp += obStack.top();
        obStack.pop();
      }
      obStack.push(c);
    }
  }
  while (!obStack.isEmpty()) {
    postExp += obStack.top();
    obStack.pop();
  }
  return postExp;
}
int eval(std::string post) {
  Tstack<int, 100> numStack;
  for (char c : post) {
    if (isdigit(c)) {
      numStack.push(c - '0');
    } else {
      int num2 = numStack.top();
      numStack.pop();
      int num1 = numStack.top();
      numStack.pop();
      switch (c) {
      case '+':
        numStack.push(num1 + num2);
        break;
      case '-':
        numStack.push(num1 - num2);
        break;
      case '*':
        numStack.push(num1 * num2);
        break;
      case '/':
        numStack.push(num1 / num2);
        break;
      case '^':
        numStack.push(pow(num1, num2));
        break;
      }
    }
  }
  return numStack.top();
}
