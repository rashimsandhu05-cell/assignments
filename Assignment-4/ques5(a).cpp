#include <iostream>
#include <queue>
using namespace std;

queue<int> q1, q2;

void push(int x) {
    q2.push(x);
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1, q2);
}

void pop() {
    if (q1.empty()) cout << "Underflow\n";
    else { cout << q1.front() << " popped\n"; q1.pop(); }
}

void top() {
    if (q1.empty()) cout << "Empty\n";
    else cout << q1.front() << "\n";
}

void display() {
    if (q1.empty()) { cout << "Empty\n"; return; }
    queue<int> t = q1;
    while (!t.empty()) { cout << t.front() << " "; t.pop(); }
    cout << "\n";
}

int main() {
    int ch, x;
    while (1) {
        cout << "1.Push 2.Pop 3.Top 4.Display 5.Exit\n";
        cin >> ch;
        if (ch == 1) { cin >> x; push(x); }
        else if (ch == 2) pop();
        else if (ch == 3) top();
        else if (ch == 4) display();
        else if (ch == 5) break;
        else cout << "Invalid\n";
    }
}
