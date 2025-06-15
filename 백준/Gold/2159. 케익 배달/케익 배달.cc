#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const int MAX = 100005;

ll n, u, v;
ll dx[5] = { 0, 0, -1, 0, +1 };
ll dy[5] = { 0, +1, 0, -1, 0 };

pair<ll,ll> arr[MAX];
ll dp[MAX * 5];

ll dfs(ll idx) {
    ll& ret = dp[idx];
    if (ret != -1) return ret;

    ll cur = idx / 5, nxt = cur + 1;
    if (nxt == n) return ret = 0;
    
    auto [x, y] = arr[cur];
    auto [nx, ny] = arr[nxt];
    x += dx[idx % 5], y += dy[idx % 5];

    ll dist = 1e15;
    for (int i = 0; i < 5; i++) {
        ll add = abs(x - (nx + dx[i])) + abs(y - (ny + dy[i]));
        dist = min(dist, dfs(nxt * 5 + i) + add);
    }

    return ret = dist;
}

int main() {
    FastIO

    cin >> n >> u >> v;
    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        arr[i] = { x, y };
    }

    ll ans = 1e15;
    memset(dp, -1, sizeof(dp));

    auto [x, y] = arr[0];
    for (int i = 0; i < 5; i++) {
        ll add = abs(u - (x + dx[i])) + abs(v - (y + dy[i]));
        ans = min(ans, dfs(i) + add);
    }
    
    cout << ans << '\n';
    return 0;
}
