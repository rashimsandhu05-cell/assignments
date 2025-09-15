#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n; 
    cin >> n;
    vector<int> diag(n);
    for (int i = 0; i < n; i++) cin >> diag[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << diag[i] << " ";
            else cout << 0 << " ";
        }
        cout << "\n";
    }
    return 0;
}
