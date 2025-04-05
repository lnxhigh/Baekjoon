#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int MAX = 1 << 10;
const int64 INF = 1LL << 60; 

int n, m;
int64 pos[MAX];
int64 sum[MAX];
int64 dp[MAX][MAX][2];

int64 dfs(int x, int y, int flag) {
    if (x == 1 && y == n) return 0;
    int64 &ret = dp[x][y][flag];
    if (ret != -1) return ret;

    ret = INF;
    int cur = x + (y - x) * flag;
    int64 amt = sum[n] - (sum[y] - sum[x - 1]);
    
    if (x > 1) {
        int64 t = pos[cur] - pos[x - 1];
        ret = min(ret, dfs(x - 1, y, 0) + t * amt);
    }
    if (y < n) {
        int64 t = pos[y + 1] - pos[cur];
        ret = min(ret, dfs(x, y + 1, 1) + t * amt);
    }

    return ret;
}

int main() {
    FastIO
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> pos[i] >> sum[i];
    }
    for (int i = 1; i <= n; i++) {
        sum[i] += sum[i - 1];
    }

    memset(dp, -1, sizeof(dp));
    int64 ans = dfs(m, m, 0);
    cout << ans << '\n';
    
    return 0;
}
