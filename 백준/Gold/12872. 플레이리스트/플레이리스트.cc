#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const ll MOD = 1'000'000'007;
const int MAX = 101;

ll n, m, p;
ll dp[MAX][MAX];

ll dfs(int i, int k) {
    ll& ret = dp[i][k];
    if (ret != -1) return ret;
    if (k == p) return ret = (i == n) ? 1 : 0;
    if (i <= m) return ret = (n - i) * dfs(i + 1, k + 1) % MOD;
    
    ret = (i - m) * dfs(i, k + 1) % MOD;
    if (i < n) ret += (n - i) * dfs(i + 1, k + 1) % MOD;
    ret %= MOD;

    return ret;
}

int main() {
    FastIO
    cin >> n >> m >> p;

    memset(dp, -1, sizeof(dp));
    ll ans = dfs(0, 0);
    cout << ans << '\n';

    return 0;
}
