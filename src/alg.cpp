// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int getPriority(char op) {
switch(c) {
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
std::string infx2pstfx(std::string inf) {
  std::string postfix;
    Tstack<char, 100>stack1;
    for (int i = 0; i < inf.length(); i++) {
        char c = inf[i];
        if (isdigit(c)) {
            postfix += c;
            postfix += ' ';
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!stack2.empty() &&
                  getPriority(stack2.top()) >= getPriority(c)) {
                postfix += stack2.top();
                stack2.pop();
            }
            stack2.push(c);
        } else if (c == '(') {
            stack2.push(c);
        } else if (c == ')') {
            while (!stack2.empty() && stack2.top() != '(') {
                postfix += stack2.top();
                stack2.pop();
            }
            if (!stack2.empty() && stack2.top() == '(') {
                stack2.pop();
            }
        }
    }
    while (!stack2.empty()) {
        postfix += stack2.top();
        stack2.pop();
    }
    return postfix;
}
int eval(std::string post) {
    Tstack<int, 100> stack2;
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
