// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
#include "alg.h"

std::string infx2pstfx(std::string inf) {
  std::string postfix;
    TStack<char, 100>stack1;
    for (int i = 0; i < inf.length(); i++) {
      if (inf[i] == '(') {
        stack1.push(inf[i]);
      } else if ((inf[i] >= '0') && (inf[i] <= '9')) {
        postfix += inf[i];
        postfix += ' ';
      } else if (inf[i] == ')') {
        while ((!stack1.isEmpty()) && (stack1.get() != '(')) {
          postfix += stack1.pop();
          postfix += ' ';
      }
        if (stack1.get() == '(') {
          stack1.pop();
              }
        } else if (inf[i] == '+' || inf[i] == '-') {
            if (!stack1.isEmpty()) {
                switch (stack1.get()) {
                    case '*': {
                        postfix += '*';
                        postfix += ' ';
                        stack1.pop();
                        break;
                    }
                    case '/': {
                        postfix += '/';
                        postfix += ' ';
                        stack1.pop();
                        break;
                    }
                    case '+': {
                        postfix += '+';
                        postfix += ' ';
                        stack1.pop();
                        break;
                    }
                    case '-': {
                        postfix += '-';
                        postfix += ' ';
          stack1.push(inf[i]);
        }
        } else if (inf[i] == '*' || inf[i] == '/') {
        if (!stack1.isEmpty()) {
          switch (stack1.get()) {
          case '*': {
                postfix += '*'
                postfix += ' ';
                stack1.pop;
                break;
        }
          case '/': {
                postfix += '/';
                postfix += ' ';
                stack1.pop();
                break;
          }
        }
        } else {
                stack1.push(inf[i]);
            }
        }
    }
    if (!stack1.empty()) {
      while (!stack1.empty()) {
      postfix += stack1.pop();
        postfix += ' ';
    }
}
int eval(std::string post) {
    TStack<int, 100> stack2;
    for (int i = 0; i < pref.length(); i++) {
        if ((pref[i] >= '0') && (pref[i] <= '9')) {
            stack2.push(pref[i] - '0');
            int operand2 = stack2.top();
            int operand1 = stack2.top();
            switch (pref(i)) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }
        }
    }
    return stack2.get();
}
