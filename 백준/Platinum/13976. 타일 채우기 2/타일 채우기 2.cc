#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
using Matrix = vector<vector<int64>>;
const int64 MOD = 1e9 + 7;
const int D = 2;
const Matrix A = { { 4, -1 }, { 1, 0 } };

Matrix operator*(const Matrix &A, const Matrix &B) {
    Matrix X = Matrix(D, vector<int64>(D, 0));

    for (int r = 0; r < D; r++) {
        for (int c = 0; c < D; c++) {
            for (int k = 0; k < D; k++) {
                int64 value = (A[r][k] * B[k][c]) % MOD;
                if (value < 0) value += MOD;
                
                X[r][c] += value;
                X[r][c] %= MOD;
            }
        }
    }

    return X;
}

Matrix operator^(const Matrix &X, int64 p) {
    if (p == 0) {
        Matrix I = Matrix(D, vector<int64>(D, 0));
        for (int i = 0; i < D; i++) I[i][i] = 1;
        return I;
    }

    Matrix S = X ^ (p / 2);
    Matrix Y = S * S;
    if (p & 1) Y = X * Y;
    
    return Y;
}

int64 solve(int64 N) {
    if (N & 1) return 0;
    N >>= 1;

    Matrix X = A ^ N;
    int64 res = (X[0][0] + X[0][1]) % MOD;
    return res;
}

int main() {
    int64 N; cin >> N;
    cout << solve(N) << '\n';
    return 0;
}
