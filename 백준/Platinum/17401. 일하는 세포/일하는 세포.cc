#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
using Matrix = vector<vector<int64>>;
const int64 MOD = 1e9 + 7;

int64 T, N, D;

Matrix operator*(const Matrix &A, const Matrix &B) {
    Matrix X = Matrix(N, vector<int64>(N, 0));

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            for (int k = 0; k < N; k++) {
                X[r][c] += A[r][k] * B[k][c];
                X[r][c] %= MOD;
            }
        }
    }

    return X;
}

Matrix operator^(const Matrix &X, int p) {
    if (p == 0) {
        Matrix I = Matrix(N, vector<int64>(N, 0));
        for (int i = 0; i < N; i++) I[i][i] = 1;
        return I;
    }

    Matrix S = X ^ (p / 2);
    Matrix Y = S * S;
    if (p & 1) Y = X * Y;
    
    return Y;
}

void print(const Matrix &X) {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cout << X[r][c] << ' ';
        }
        cout << '\n';
    }
    return;
}

int main() {
    FastIO
    cin >> T >> N >> D;
    vector<Matrix> M(T+1);
    for (int i = 0; i <= T; i++) {
        M[i] = Matrix(N, vector<int64>(N, 0));
    }
    for (int i = 0; i <  N; i++) {
        M[0][i][i] = 1;
    }

    for (int i = 1; i <= T; i++) {
        Matrix X = Matrix(N, vector<int64>(N, 0));
        int K; cin >> K;

        for (int k = 0; k < K; k++) {
            int a, b, c;
            cin >> a >> b >> c;
            X[--a][--b] = c;
        }

        M[i] = M[i-1] * X;
    }

    Matrix X = (M[T] ^ (D / T)) * M[D % T];
    print(X);
    
    return 0;
}
