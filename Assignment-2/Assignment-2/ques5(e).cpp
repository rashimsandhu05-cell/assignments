#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> sym(n*(n+1)/2);
    for (int i = 0; i < sym.size(); i++) cin >> sym[i];
    int k = 0;
    vector<vector<int>> mat(n, vector<int>(n,0));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            mat[i][j] = sym[k];
            mat[j][i] = sym[k];
            k++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << mat[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
