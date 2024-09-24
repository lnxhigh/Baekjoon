#include <bits/stdc++.h>
using namespace std;
using Matrix = vector<vector<int>>;
const int MOD = 9901;

// O(log N) solution with matrix

const int D = 3;
const Matrix A = {
    {1, 1, 1}, 
    {1, 0, 1}, 
    {1, 1, 0}
};

Matrix operator*(const Matrix &A, const Matrix &B) {
    Matrix X = Matrix(D, vector<int>(D, 0));

    for (int r = 0; r < D; r++) {
        for (int c = 0; c < D; c++) {
            for (int k = 0; k < D; k++) {
                X[r][c] += A[r][k] * B[k][c];
                X[r][c] %= MOD;
            }
        }
    }

    return X;
}

Matrix operator^(const Matrix &X, int p) {
    if (p == 0) {
        Matrix I = Matrix(D, vector<int>(D, 0));
        for (int i = 0; i < D; i++) I[i][i] = 1;
        return I;
    }

    Matrix S = X ^ (p / 2);
    Matrix Y = S * S;
    if (p & 1) Y = X * Y;
    
    return Y;
}

int main() {
    int N; cin >> N;
    Matrix X = A ^ N;

    int res = X[0][0] + X[1][0] + X[2][0];
    res %= MOD;
    cout << res << '\n';
    
    return 0;
}
