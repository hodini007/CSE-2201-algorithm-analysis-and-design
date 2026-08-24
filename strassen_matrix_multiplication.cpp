#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Matrix;

Matrix add(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

Matrix subtract(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

Matrix strassenMultiply(const Matrix& A, const Matrix& B) {
    int n = A.size();
    if (n == 0) return {};
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int half = n / 2;

    Matrix A11(half, vector<int>(half));
    Matrix A12(half, vector<int>(half));
    Matrix A21(half, vector<int>(half));
    Matrix A22(half, vector<int>(half));

    Matrix B11(half, vector<int>(half));
    Matrix B12(half, vector<int>(half));
    Matrix B21(half, vector<int>(half));
    Matrix B22(half, vector<int>(half));

    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    Matrix M1 = strassenMultiply(add(A11, A22), add(B11, B22));
    Matrix M2 = strassenMultiply(add(A21, A22), B11);
    Matrix M3 = strassenMultiply(A11, subtract(B12, B22));
    Matrix M4 = strassenMultiply(A22, subtract(B21, B11));
    Matrix M5 = strassenMultiply(add(A11, A12), B22);
    Matrix M6 = strassenMultiply(subtract(A21, A11), add(B11, B12));
    Matrix M7 = strassenMultiply(subtract(A12, A22), add(B21, B22));

    Matrix C11 = subtract(add(add(M1, M4), M7), M5);
    Matrix C12 = add(M3, M5);
    Matrix C21 = add(M2, M4);
    Matrix C22 = subtract(add(add(M1, M3), M6), M2);

    Matrix C(n, vector<int>(n));
    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }
    return C;
}

void printMatrix(const Matrix& M) {
    for (const auto& row : M) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << "\n";
    }
}

int main() {
    Matrix mat1 = {
        {1, 4, 2, 1},
        {3, 5, 5, 6},
        {3, 6, 2, 7},
        {3, 2, 1, 9}
    };

    Matrix mat2 = {
        {1, 7, 2, 0},
        {5, 3, 7, 3},
        {6, 7, 2, 6},
        {8, 3, 5, 2}
    };

    Matrix ans = strassenMultiply(mat1, mat2);
    printMatrix(ans);
    return 0;
}