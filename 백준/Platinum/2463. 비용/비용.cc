#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const ll MAX = 101'010LL;
const ll MOD = 1'000'000'000LL;

ll n, m;
vector<tuple<ll,int,int>> edges;

int par[MAX];
ll sz[MAX];

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    else if (x < y) swap(x, y);
    
    par[x] = y;
    sz[y] = (sz[y] + sz[x]) % MOD;
    return true;
}

int main() {
    FastIO

    cin >> n >> m;
    edges.resize(m);
    for (auto& [w, x, y] : edges) cin >> x >> y >> w, --x, --y;
    sort(edges.rbegin(), edges.rend());

    ll ans = 0, cnt = 0;
    iota(par, par + MAX, 0);
    fill(sz, sz + MAX, 1);

    for (const auto& [w, x, y] : edges) {
        ll add = sz[find(x)] * sz[find(y)] % MOD;
        bool chk = merge(x, y);

        if (chk) cnt = (cnt + add) % MOD;
        ans = (ans + w * cnt) % MOD;
    }
    
    cout << ans << '\n';
    return 0;
}
