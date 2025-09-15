#include <iostream>
#include <vector>
using namespace std;

int missingLinear(const vector<int>& a, int n) {
    long long expected = 1LL * n * (n + 1) / 2;
    long long actual = 0;
    for (int x : a) actual += x;
    return int(expected - actual);
}

int missingBinary(const vector<int>& a, int n) {
    int l = 0, r = (int)a.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == m + 1) l = m + 1;
        else r = m - 1;
    }
    return l + 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; i++) cin >> a[i];
    cout << "Missing (Linear): " << missingLinear(a, n) << "\n";
    cout << "Missing (Binary): " << missingBinary(a, n) << "\n";
    return 0;
}
