#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
#define For(i, n) for (int i = 0; i < n; i++)
using namespace std;

int R, C, N;
const int MAX = 1 << 8;
char A[MAX][MAX], B[MAX][MAX], C_[MAX][MAX], D[MAX][MAX], E[MAX][MAX];

void print(char X[MAX][MAX]) {
    For (r, R) {
        For (c, C) {
            cout << X[r][c];
        }
        cout << '\n';
    }
    cout << '\n';
}

void solve(int T) {
    if (T <= 1) print(A);
    else if (T == 2) print(B);
    else if (T == 3) print(C_);
    else if (T == 4) print(D);
    else if (T == 5) print(E);
    else {
        T = T % 4 + 4;
        if (T >= 6) T -= 4;
        solve(T);
    }

    return;
}

int main() {
    FastIO
    cin >> R >> C >> N;

    // T <= 1
    For (r, R) {
        For (c, C) {
            cin >> A[r][c];
        }
    }

    // T == 2
    For (r, R) {
        For (c, C) {
            B[r][c] = 'O';
        }
    }

    // T == 3
    int dr[4] = { -1, 0, +1, 0 };
    int dc[4] = { 0, -1, 0, +1 };

    For (r, R) {
        For (c, C) {
            C_[r][c] = 'O';
        }
    }

    For (r, R) {
        For (c, C) {
            if (A[r][c] == 'O') {
                C_[r][c] = '.';
                For (d, 4) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                    C_[nr][nc] = '.';
                }
            }
        }
    }

    // T == 4
    For (r, R) {
        For (c, C) {
            D[r][c] = 'O';
        }
    }

    // T == 5
    For (r, R) {
        For (c, C) {
            E[r][c] = 'O';
        }
    }

    For (r, R) {
        For (c, C) {
            if (C_[r][c] == 'O') {
                E[r][c] = '.';
                For (d, 4) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                    E[nr][nc] = '.';
                }
            }
        }
    }
    
    // Answer
    solve(N);
    
    return 0;
}
