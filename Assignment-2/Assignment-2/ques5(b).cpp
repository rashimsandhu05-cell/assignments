#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n; 
    cin >> n;
    vector<int> tri(3*n - 2);
    for (int i = 0; i < 3*n - 2; i++) cin >> tri[i];
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(i - j) <= 1) cout << tri[k++] << " ";
            else cout << 0 << " ";
        }
        cout << "\n";
    }
    return 0;
}
