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
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    char str[MAX];
    cout << "Enter a string: ";
    cin.getline(str, MAX);
    Stack s;
    for (int i = 0; str[i] != '\0'; i++)
        s.push(str[i]);
    cout << "Reversed string: ";
    while (!s.isEmpty())
        cout << s.pop();
    cout << endl;
    return 0;
}
