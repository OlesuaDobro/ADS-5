// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int getPriority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else {
        return 0;
    }
}
std::string infx2pstfx(std::string inf) {
    string postfix;
    Tstack<char, 100> operatorStack;
    for (int i = 0; i < inf.length(); i++) {
        char c = inf[i];
        if (isdigit(c)) {
            postfix += c;
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
    Tstack<int, 100> operandStack;
    for (int i = 0; i < post.length(); i++) {
        char c = post[i];
        if (isdigit(c)) {
            operandStack.push(c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();
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
            operandStack.push(result);
        }
    }
    return operandStack.top();
}
