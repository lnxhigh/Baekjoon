#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
using Matrix = vector<vector<int64>>;
const int64 MOD = 1000000009;

// O(log N) solution with matrix

const int D = 3;
const Matrix A = {
    {1, 1, 1}, 
    {1, 0, 0}, 
    {0, 1, 0}
};

Matrix operator*(const Matrix &A, const Matrix &B) {
    Matrix X = Matrix(D, vector<int64>(D, 0));

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
        Matrix I = Matrix(D, vector<int64>(D, 0));
        for (int i = 0; i < D; i++) I[i][i] = 1;
        return I;
    }

    Matrix S = X ^ (p / 2);
    Matrix Y = S * S;
    if (p & 1) Y = X * Y;
    
    return Y;
}

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        Matrix X = A ^ N;
        cout << X[0][0] << '\n';
    }

    return 0;
}
