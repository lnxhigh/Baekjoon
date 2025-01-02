#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 21;
const int INF = 1 << 30;

int N;
int A[MAX][MAX];

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
}

int f(int x, int y, int d1, int d2) {
    int D[MAX][MAX];
    memset(D, 0, sizeof(D));

    for (int i = 0; i <= d1; i++) {
        int cx = x + i, cy = y - i;
        for (int j = 0; j <= d2; j++) {
            int nx = cx + j, ny = cy + j;
            D[nx][ny] = 5;
        }
    }

    // 5
    for (int i = 0; i < d1; i++) {
        int cx = x + 1 + i, cy = y - i;
        for (int j = 0; j < d2; j++) {
            int nx = cx + j, ny = cy + j;
            D[nx][ny] = 5;
        }
    }
    
    // 1
    for (int row = 0; row < x + d1; row++) {
        for (int col = 0; col <= y; col++) {
            if (D[row][col]) break;
            D[row][col] = 1;
        }
    }

    // 2
    for (int row = 0; row <= x + d2; row++) {
        for (int col = N - 1; col > y; col--) {
            if (D[row][col]) break;
            D[row][col] = 2;
        }
    }

    // 3
    for (int row = x + d1; row < N; row++) {
        for (int col = 0; col < y - d1 + d2; col++) {
            if (D[row][col]) break;
            D[row][col] = 3;
        }
    }

    // 4
    for (int row = x + d2 + 1; row < N; row++) {
        for (int col = N - 1; col >= y - d1 + d2; col--) {
            if (D[row][col]) break;
            D[row][col] = 4;
        }
    }

    // Difference
    int X[5] = { 0, 0, 0, 0, 0 };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            X[D[i][j] - 1] += A[i][j];
        }
    }

    sort(X, X + 5);
    if (!X[0]) return INF;
    return X[4] - X[0];
}

int solve() {
    int diff = INF;

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            for (int d1 = 1; d1 < N; d1++) {
                for (int d2 = 1; d2 < N; d2++) {
                    if (x + d1 + d2 >= N || y - d1 < 0 || y + d2 >= N) continue;
                    diff = min(diff, f(x, y, d1, d2));
                }
            }
        }
    }

    return diff;
}

int main() {
    FastIO
    input();
    int ans = solve();
    cout << ans << '\n';
    return 0;
}
