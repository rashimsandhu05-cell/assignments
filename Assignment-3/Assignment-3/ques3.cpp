#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    void push(char c) {
        if (top == MAX - 1) return;
        arr[++top] = c;
    }
    char pop() {
        if (top == -1) return '\0';
        return arr[top--];
    }
    char peek() {
        if (top == -1) return '\0';
        return arr[top];
    }
    bool isEmpty() {
        return top == -1;
    }
};

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(const char* exp) {
    Stack s;
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            s.push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (s.isEmpty() || !isMatchingPair(s.pop(), exp[i]))
                return false;
        }
    }
    return s.isEmpty();
}

int main() {
    char exp[MAX];
    cout << "Enter expression: ";
    cin.getline(exp, MAX);
    if (isBalanced(exp))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";
    return 0;
}
