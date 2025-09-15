#include <bits/stdc++.h>
using namespace std;

bool isOperator(const string &t) {
    return t.size() == 1 && (t[0] == '+' || t[0] == '-' || t[0] == '*' || t[0] == '/' || t[0] == '^');
}

int main() {
    string line;
    cout << "Enter postfix expression (tokens separated by spaces):\n";
    getline(cin, line);
    istringstream iss(line);
    stack<double> st;
    string token;
    bool error = false;

    while (iss >> token) {
        if (isOperator(token)) {
            if (st.size() < 2) { error = true; break; }
            double b = st.top(); st.pop();
            double a = st.top(); st.pop();
            double res = 0;
            char op = token[0];
            if (op == '+') res = a + b;
            else if (op == '-') res = a - b;
            else if (op == '*') res = a * b;
            else if (op == '/') {
                if (b == 0) { cout << "Error: Division by zero\n"; return 0; }
                res = a / b;
            } else if (op == '^') res = pow(a, b);
            st.push(res);
        } else {
            try {
                double val = stod(token);
                st.push(val);
            } catch (...) {
                error = true;
                break;
            }
        }
    }

    if (error || st.size() != 1) {
        cout << "Invalid postfix expression\n";
        return 0;
    }

    double result = st.top();
    if (fabs(result - round(result)) < 1e-12) cout << (long long) llround(result) << '\n';
    else cout << result << '\n';
    return 0;
}
