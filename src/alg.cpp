// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
    std::string pst;
    std::Tstack<char> st;
for (int i = 0; i < inf.length(); i++) {
        if (isdigit(inf[i]))
            pst += inf[i];
} else if (inf[i] == '(') {
            st.push(inf[i]);
} else if (inf[i] == '+' || inf[i] == '-' ||
            inf[i] == '*' || inf[i] == '/') {
            while (!st.empty() && st.top() != '(' && (st.top() == '*' || st.top() == '/'))
            {
                pst += st.top();
                st.pop();
            }
            st.push(inf[i]);
} else if (inf[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                pst += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
    }
}
    while (!st.empty()) {
        pst += st.top();
        st.pop();
    }
    return pst;
}
int eval(std::string post) {
    std::Tstack<int> st;
    for (int i = 0; i < post.length(); i++) {
        if (isdigit(post[i])) {
            int num = 0;
            while (i < post.length() && isdigit(post[i])) {
                num = num * 10 + (post[i] - '0');
                i++;
            }
            st.push(num);
        } else if (post[i] == '+' || post[i] == '-' || post[i] == '*' || post[i] == '/') {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();
            int result;
            switch (post[i]) {
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
            st.push(result);
        }
    }
    return st.top();
}
