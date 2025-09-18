#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<char> q;
    int freq[256] = {0};
    char c;
    while (cin >> c) {
        freq[c]++;
        q.push(c);
        while (!q.empty() && freq[q.front()] > 1) q.pop();
        if (q.empty()) cout << -1 << " ";
        else cout << q.front() << " ";
    }
    return 0;
}
