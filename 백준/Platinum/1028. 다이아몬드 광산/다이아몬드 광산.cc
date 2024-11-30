#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 751;

int R, C;
bool A[MAX][MAX];
int D[MAX][MAX][4];

// ↖ ↙ ↘ ↗
int dx[4] = { -1, +1, +1, -1 };
int dy[4] = { -1, -1, +1, +1 };

void input() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char x; cin >> x;
            A[i][j] = (x == '1');
        }
    }
}

bool inside(int x, int y) {
    if (x < 0 || x >= R || y < 0 || y >= C) return false;
    return true;
}

int dfs(int x, int y, int k) {
    if (!inside(x, y)) return 0;
    if (D[x][y][k] != -1) return D[x][y][k];
    else if (!A[x][y]) return D[x][y][k] = 0;
    return D[x][y][k] = dfs(x - dx[k], y - dy[k], k) + 1;
}

int len(int x, int y, int m) {
    // ↖ ↙ ↘ ↗
    int ret = 0;
    int k = min(D[x][y][0], D[x][y][3]);
    for (int i = m; i < k; i++) {
        int a = D[x + i * dx[2]][y + i * dy[2]][3];
        int b = D[x + i * dx[1]][y + i * dy[1]][0];
        if (min(a, b) > i) ret = max(ret, i + 1);
    }

    return ret;
}

void sum() {
    memset(D, -1, sizeof(D));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            for (int k = 0; k < 4; k++) {
                dfs(i, j, k);
            }
        }
    }
}

int solve() {
    int x = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            x = max(x, len(i, j, x));
        }
    }
    
    return x;
}

int main() {
    FastIO
    input();
    sum();

    int ans = solve();
    cout << ans << '\n';
    return 0;
}
