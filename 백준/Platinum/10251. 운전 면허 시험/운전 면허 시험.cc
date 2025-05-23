#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100;
const int INF = 1 << 28;

int tc;
int r, c, l, g;
int arr[MAX][MAX][2];
int dp[MAX][MAX][MAX << 1][2];

int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };

void input() {
    cin >> r >> c >> l >> g;
    memset(dp, -1, sizeof(dp));
    
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c - 1; j++)
            cin >> arr[i][j][0];

    for (int i = 0; i < r - 1; i++)
        for (int j = 0; j < c; j++) 
            cin >> arr[i][j][1];
}

int dfs(int x, int y, int cnt, int dir) {
    int& ret = dp[x][y][cnt][dir];
    if (ret != -1) return ret;
    else if (x == r - 1 && y == c - 1) return ret = 0;

    ret = INF;

    for (int i = 0; i <= 1; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;

        int nc = (i == dir) ? cnt : cnt - 1;
        if (nc < 0) continue;

        ret = min(ret, dfs(nx, ny, nc, i) + arr[x][y][i]);
    }

    return ret;
}

int main() {
    FastIO
    cin >> tc;
    
    while (tc--) {
        input();

        int ans = INF;

        for (int t = 1; t < r + c && ans >= INF; t++) {
            int amt = min(dfs(0, 0, t, 0), dfs(0, 0, t, 1));
            if (amt <= g) ans = min(ans, t + (r + c - 2) * l);
        }
        
        if (ans >= INF) ans = -1;
        cout << ans << '\n';
    }

    return 0;
}
