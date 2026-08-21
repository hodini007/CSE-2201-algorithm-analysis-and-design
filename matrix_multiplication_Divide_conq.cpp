#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int> >matrix ;

matrix add(const matrix& A, const matrix& B) {
    int n = A.size();
    matrix C(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

matrix multi(matrix m1, matrix m2) {
    int n = m1.size();
    matrix res(n, vector<int>(n));

    // Base case: 1x1 matrix (0-indexed in C++)
    if (n == 1) {
        res[0][0] = m1[0][0] * m2[0][0];
        return res;
    }

    int half = n / 2;

    matrix A11(half, vector<int>(half)), A12(half, vector<int>(half));
    matrix A21(half, vector<int>(half)), A22(half, vector<int>(half));
    matrix B11(half, vector<int>(half)), B12(half, vector<int>(half));
    matrix B21(half, vector<int>(half)), B22(half, vector<int>(half));

    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            A11[i][j] = m1[i][j];
            A12[i][j] = m1[i][j + half];
            A21[i][j] = m1[i + half][j];
            A22[i][j] = m1[i + half][j + half];

            B11[i][j] = m2[i][j];
            B12[i][j] = m2[i][j + half];
            B21[i][j] = m2[i + half][j];
            B22[i][j] = m2[i + half][j + half];
        }
    }

    matrix C11 = add(multi(A11, B11), multi(A12, B21));
    matrix C12 = add(multi(A11, B12), multi(A12, B22));
    matrix C21 = add(multi(A21, B11), multi(A22, B21));
    matrix C22 = add(multi(A21, B12), multi(A22, B22));

    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            res[i][j]                 = C11[i][j];
            res[i][j + half]          = C12[i][j];
            res[i + half][j]          = C21[i][j];
            res[i + half][j + half]   = C22[i][j];
        }
    }

    return res;
}


int main(){

matrix mat1 ={
    {1,4,2,1},
    {3,5,5,6},
    {3,6,2,7},
    {3,2,1,9}
};

matrix mat2 ={
    {1,7,2,0},
    {5,3,7,3},    
    {6,7,2,6},
    {8,3,5,2}
};


matrix ans= multi(mat1,mat2);    
for (int i = 0; i < ans.size(); i++)
{
    for (int j = 0; j < ans.size(); j++)
    {
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;



};

}