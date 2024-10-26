#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;
int A[MAX][MAX];
int D[MAX][MAX][3];
int dx[2] = { -1, 0 };
int dy[2] = { 0, -1 };

int dfs(int x, int y, int k) {
    int& res = D[x][y][k];
    if (res != -1) return res;
    if (x == 0 && y == 0) return res = (A[x][y] == k && k == 0);

    for (int i = 0; i < 2; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0) continue;

        res = max(res, dfs(nx, ny, k));
        if (A[x][y] != k) continue;
        
        int cnt = dfs(nx, ny, (k + 2) % 3);
        if (cnt >= k) res = max(res, cnt + 1);
    }

    return res;
}

int main() {
    FastIO
    int N; cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    int ans = 0;
    memset(D, -1, sizeof(D));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 3; k++) {
                ans = max(ans, dfs(i, j, k));
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
