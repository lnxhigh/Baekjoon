#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 105;
const int MOD = 1'000'000;

int n;
int dp[2][MAX][MAX];

int dfs(bool flag, int x, int y) {
    if (x < 0 || y < 0) return 0;

    int& ret = dp[flag][x][y];
    if (ret != -1) return ret;
    else if (x == 0 && y == 0) return ret = 1;

    int sum = 0;

    if (flag) {
        for (int i = 0; i < x; i++) {
            sum += dfs(!flag, i, x + y - i - 1);
        }
    }
    else {
        for (int i = 0; i < y; i++) {
            sum += dfs(!flag, x + i, y - i - 1);
        }
    }
    
    return ret = sum % MOD;
}

int main() {
    FastIO
    cin >> n;

    memset(dp, -1, sizeof(dp));

    int ans = 0;

    if (n == 1) {
        ans = 1;
    }
    else {
        for (int i = 0; i < n; i++) {
            ans += dfs(true, i, n - 1 - i);
            ans += dfs(false, i, n - 1 - i);
        }
    }
    
    ans %= MOD;
    cout << ans << '\n';
    return 0;
}
