#include <iostream>
using namespace std;

struct Term {
    int row, col, val;
};

struct Sparse {
    int rows, cols, terms;
    Term data[50];  // enough space for non-zero terms
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

Sparse add(Sparse a, Sparse b) {
    Sparse c;
    if (a.rows != b.rows || a.cols != b.cols) {
        c.terms = 0; 
        return c;
    }
    c.rows = a.rows; 
    c.cols = a.cols;

    int i = 0, j = 0, k = 0;
    while (i < a.terms && j < b.terms) {
        if (a.data[i].row == b.data[j].row && a.data[i].col == b.data[j].col) {
            int sum = a.data[i].val + b.data[j].val;
            if (sum != 0) {
                c.data[k].row = a.data[i].row;
                c.data[k].col = a.data[i].col;
                c.data[k].val = sum;
                k++;
            }
            i++; j++;
        }
        else if (a.data[i].row < b.data[j].row || 
                (a.data[i].row == b.data[j].row && a.data[i].col < b.data[j].col)) {
            c.data[k++] = a.data[i++];
        }
        else {
            c.data[k++] = b.data[j++];
        }
    }
    while (i < a.terms) c.data[k++] = a.data[i++];
    while (j < b.terms) c.data[k++] = b.data[j++];

    c.terms = k;
    return c;
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

    int B[10][10] = {
        {0, 2, 0},
        {0, 0, 7},
        {0, 5, 0}
    };

    Sparse sA = createSparse(3, 3, A);
    Sparse sB = createSparse(3, 3, B);

    cout << "Matrix A (Triplet):\n"; printSparse(sA);
    cout << "Matrix B (Triplet):\n"; printSparse(sB);

    Sparse sC = add(sA, sB);
    cout << "A + B (Triplet):\n"; printSparse(sC);

    return 0;
}
