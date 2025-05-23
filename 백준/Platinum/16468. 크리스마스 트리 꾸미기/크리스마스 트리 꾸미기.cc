#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const ll MAX = 301;
const ll MOD = 100'030'001;

ll n, l;
ll dp[MAX][MAX];

ll dfs(ll x, ll h) {
    ll& ret = dp[x][h];
    if (ret != -1) return ret;
    
    if (x == 0) return ret = 1;
    else if (h == 0) return ret = 0;

    ll sum = 0;
    for (ll i = 0; i < x; i++) {
        sum += (dfs(i, h - 1) * dfs(x - 1 - i, h - 1)) % MOD;
    }
    
    return ret = sum % MOD;
}

int main() {
    FastIO
    cin >> n >> l;

    memset(dp, -1, sizeof(dp));
    ll ans = (dfs(n, l) - dfs(n, l - 1) + MOD) % MOD;
    cout << ans << '\n';

    return 0;
}
