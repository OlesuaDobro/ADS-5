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
            while (!operatorStack.empty() &&
                  getPriority(operatorStack.top()) >= getPriority(c)) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        } else if (c == '(') {
            operatorStack.push(c);
        } else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty() && operatorStack.top() == '(') {
                operatorStack.pop();
            }
        }
    }
    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }
    return postfix;
}
int eval(std::string post) {
    Tstack<int, 100> stack1;
    for (int i = 0; i < post.length(); i++) {
        char c = post[i];
        if (isdigit(c)) {
            stack1.push(c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int operand2 = stack1.top();
            stack1.pop();
            int operand1 = stack1.top();
            stack1.pop();
            int result;
            switch (c) {
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
            stack1.push(result);
        }
    }
    return stack1.top();
}
