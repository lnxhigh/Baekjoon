#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const ll MAX = 210'001LL;
const ll INF = 1LL << 55;

ll n;
ll arr[MAX];
ll dp[MAX][5];

ll dfs(ll idx, ll last) {
    ll& ret = dp[idx][last];
    if (ret != -1) return ret;
    else if (idx == n) return ret = 0;

    ret = -INF;
    ll x = 0;

    for (ll i = 0; i < 5 && idx + i < n; i++) {
        x ^= arr[idx + i];
        if (i == last) continue;
        ret = max(ret, dfs(idx + i + 1, i) + x);
    }
    return ret;
}

int main() {
    FastIO
    cin >> n;
    for (ll i = 0; i < n; i++) cin >> arr[i];

    ll ans = 0;

    memset(dp, -1, sizeof(dp));
    for (ll i = 0; i < 5; i++) {
        ans = max(ans, dfs(0, i));  
    }
    cout << ans << '\n';

    return 0;
}
