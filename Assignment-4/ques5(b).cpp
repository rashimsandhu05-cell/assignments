#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

void push(int x) {
    q.push(x);
    for (int i = 0; i < (int)q.size() - 1; i++) {
        q.push(q.front());
        q.pop();
    }
}

void pop() {
    if (q.empty()) cout << "Empty\n";
    else { cout << q.front() << " popped\n"; q.pop(); }
}

void top() {
    if (q.empty()) cout << "Empty\n";
    else cout << q.front() << "\n";
}

int main() {
    int ch, x;
    while (1) {
        cout << "1.Push 2.Pop 3.Top 4.Exit\n";
        cin >> ch;
        if (ch == 1) { cin >> x; push(x); }
        else if (ch == 2) pop();
        else if (ch == 3) top();
        else if (ch == 4) break;
    }
}
