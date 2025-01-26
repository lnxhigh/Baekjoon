#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int MAX = 305;
const int64 MOD = 1'000'000'007;

int R, C, L;
string S;
char A[MAX][MAX];
int64 X[MAX][MAX], D[MAX][MAX];

int64 sum(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) return 0;
    else if (x1 < 0 || x1 >= R || y1 < 0 || y1 >= C) return 0;
    else if (x2 < 0 || x2 >= R || y2 < 0 || y2 >= C) return 0;
    
    int64 ret = D[x2][y2];
    if (x1 != 0) ret -= D[x1 - 1][y2];
    if (y1 != 0) ret -= D[x2][y1 - 1];
    if (x1 != 0 && y1 != 0) ret += D[x1 - 1][y1 - 1];

    ret %= MOD;
    return (ret + MOD) % MOD;
}

int64 f(int x, int y) {
    int64 ret = 0;
    ret += sum(0, y + 2, x - 2, C - 1) - sum(x - 2, y + 2, x - 2, y + 2);
    ret += sum(0, 0, x - 2, y - 2) - sum(x - 2, y - 2, x - 2, y - 2);
    ret += sum(x + 2, 0, R - 1, y - 2) - sum(x + 2, y - 2, x + 2, y - 2);
    ret += sum(x + 2, y + 2, R - 1, C - 1) - sum(x + 2, y + 2, x + 2, y + 2);
    
    ret %= MOD;
    return (ret + MOD) % MOD;
}

int main() {
    FastIO
    cin >> R >> C >> L;
    cin >> S;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> A[i][j];
        }
    }

    for (int idx = 0; idx < (int) S.size(); idx++) {
        // update dp table
        memset(X, 0, sizeof(X));
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (A[r][c] != S[idx]) continue;
                if (idx == 0) X[r][c] = 1;
                else X[r][c] = f(r, c);
            }
        }

        // update cumulative sum
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                D[r][c] = X[r][c];
                if (r != 0) D[r][c] += D[r - 1][c];
                if (c != 0) D[r][c] += D[r][c - 1];
                if (r != 0 && c != 0) D[r][c] -= D[r - 1][c - 1];

                D[r][c] %= MOD;
                D[r][c] = (D[r][c] + MOD) % MOD;
            }
        }
    }

    cout << D[R - 1][C - 1] << '\n';
    return 0;
}
