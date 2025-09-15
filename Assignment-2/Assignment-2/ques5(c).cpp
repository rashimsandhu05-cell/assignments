#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n; 
    cin >> n;
    vector<int> low(n*(n+1)/2);
    for (int i = 0; i < low.size(); i++) cin >> low[i];
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) cout << low[k++] << " ";
            else cout << 0 << " ";
        }
        cout << "\n";
    }
    return 0;
}
