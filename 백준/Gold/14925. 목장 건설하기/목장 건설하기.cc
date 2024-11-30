#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int R, C;
int A[MAX][MAX];
int D[MAX][MAX];

int H[MAX][MAX];
int W[MAX][MAX];

void input() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> A[i][j];
        }
    }
}

void init() {
    memset(D, -1, sizeof(D));

    for (int row = 0; row < R; row++) {
        W[row][0] = (A[row][0] == 0);
        for (int i = 1; i < C; i++) {
            if (A[row][i] != 0) continue;
            W[row][i] = W[row][i - 1] + 1;
        }
    }

    for (int col = 0; col < C; col++) {
        H[0][col] = (A[0][col] == 0);
        for (int i = 1; i < R; i++) {
            if (A[i][col] != 0) continue;
            H[i][col] = H[i - 1][col] + 1;
        }
    }
}

// (x, y) 를 우하단 꼭짓점으로 하는 정사각형의 한 변의 최대 길이
int dfs(int x, int y) {
    if (x < 0 || y < 0) return 0;
    if (D[x][y] != -1) return D[x][y];
    if (A[x][y] != 0) return D[x][y] = 0;

    int sq = dfs(x - 1, y - 1) + 1;
    int len = min(W[x][y], H[x][y]);
    return D[x][y] = min(sq, len);
}

int solve() {
    int ans = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            ans = max(ans, dfs(i, j));
        }
    }

    return ans;
}

int main() {
    FastIO
    input();
    init();

    int ans = solve();
    cout << ans << '\n';
    return 0;
}
