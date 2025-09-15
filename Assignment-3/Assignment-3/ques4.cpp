#include <bits/stdc++.h>
using namespace std;

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/' || c == '%') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

string infixToPostfix(const string &infix) {
    string expr;
    for (char c : infix) if (c != '\t') expr.push_back(c);
    stack<char> st;
    string output;
    st.push('(');
    string s = expr + ')';
    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (isspace(c)) continue;
        if (isalnum(c)) {
            output.push_back(c);
            // gather multi-char operand if next characters are alnum
            while (i + 1 < s.size() && isalnum(s[i+1])) {
                output.push_back(s[++i]);
            }
            output.push_back(' ');
        } else if (c == '(') {
            st.push(c);
        } else if (isOperator(c)) {
            while (!st.empty() && isOperator(st.top())) {
                char topOp = st.top();
                int pTop = precedence(topOp);
                int pCur = precedence(c);
                if (pTop > pCur || (pTop == pCur && c != '^')) {
                    output.push_back(topOp);
                    output.push_back(' ');
                    st.pop();
                } else break;
            }
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                output.push_back(st.top());
                output.push_back(' ');
                st.pop();
            }
            if (!st.empty() && st.top() == '(') st.pop();
        } else {
            // ignore any other characters
        }
    }
    while (!st.empty()) {
        if (st.top() != '(') {
            output.push_back(st.top());
            output.push_back(' ');
        }
        st.pop();
    }
    if (!output.empty() && output.back() == ' ') output.pop_back();
    return output;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << "\n";
    return 0;
}
