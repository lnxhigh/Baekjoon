#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int A[100][100], B[100][100], C[100][100];

void input(int matrix[100][100], int &N, int &M) {
    cin >> N >> M;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> matrix[r][c];
        }
    }
}

void output(const int matrix[100][100], const int N, const int M) {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cout << matrix[r][c] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void multiply(
    int matrix[100][100], const int N, const int M, const int K, 
    const int A[100][100], const int B[100][100]) {
    
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < K; c++) {
            matrix[r][c] = 0;
            for (int i = 0; i < M; i++) {
                matrix[r][c] += A[r][i] * B[i][c];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input(A, N, M);
    input(B, M, K);

    multiply(C, N, M, K, A, B);
    output(C, N, K);

    return 0;
}
