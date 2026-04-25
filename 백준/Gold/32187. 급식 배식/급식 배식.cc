#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const ll MAX = 100'001;

ll n, m;
vector<pair<ll,ll>> dat[MAX];

int main() {
    FastIO
    
    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        ll len, p, v; cin >> len;
        while (len--) cin >> p >> v, dat[p].emplace_back(i, v);
    }

    ll ans = 0;

    for (ll i = 1; i <= n; i++) {
        if (dat[i].empty()) continue;
        sort(dat[i].begin(), dat[i].end());

        ll len = dat[i].size();
        
        vector<ll> x(len), y(len);
        x[0] = dat[i][0].second, y[0] = 0;

        for (ll j = 1; j < len; j++) {
            ll cur = dat[i][j].first;
            ll prv = dat[i][j - 1].first;
            ll add = dat[i][j].second;
            
            x[j] = (cur == prv + 1) ? y[j - 1] + add : max(x[j - 1], y[j - 1]) + add;
            y[j] = max(x[j - 1], y[j - 1]);
        }

        ans += max(x[len - 1], y[len - 1]);
    }

    cout << ans << '\n';
    return 0;
}
