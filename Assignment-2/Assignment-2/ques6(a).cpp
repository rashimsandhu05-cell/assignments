#include <iostream>
using namespace std;

struct Term {
    int row, col, val;
};

struct Sparse {
    int rows, cols, terms;
    Term data[20];   // fixed-size array for simplicity
};

Sparse createSparse(int r, int c, int mat[10][10]) {
    Sparse s;
    s.rows = r; 
    s.cols = c; 
    s.terms = 0;

    int k = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] != 0) {
                s.data[k].row = i;
                s.data[k].col = j;
                s.data[k].val = mat[i][j];
                k++;
            }
        }
    }
    s.terms = k;
    return s;
}

Sparse transpose(Sparse s) {
    Sparse t;
    t.rows = s.cols; 
    t.cols = s.rows; 
    t.terms = s.terms;

    int k = 0;
    for (int i = 0; i < s.cols; i++) {
        for (int j = 0; j < s.terms; j++) {
            if (s.data[j].col == i) {
                t.data[k].row = s.data[j].col;
                t.data[k].col = s.data[j].row;
                t.data[k].val = s.data[j].val;
                k++;
            }
        }
    }
    return t;
}

void printSparse(Sparse s) {
    cout << "Row Col Val\n";
    for (int i = 0; i < s.terms; i++) {
        cout << s.data[i].row << " " << s.data[i].col << " " << s.data[i].val << endl;
    }
}

int main() {
    int A[10][10] = {
        {0, 0, 3},
        {4, 0, 0},
        {0, 5, 0}
    };

    Sparse sA = createSparse(3, 3, A);
    cout << "Matrix A (Triplet):\n"; 
    printSparse(sA);

    Sparse tA = transpose(sA);
    cout << "Transpose of A:\n"; 
    printSparse(tA);

    return 0;
}
