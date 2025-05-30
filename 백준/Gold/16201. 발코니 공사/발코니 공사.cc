#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const ll MAX = 1 << 10;
const ll MOD = 1'000'000'007;

ll r, c, k;
vector<ll> dat[MAX];
map<ll,ll> mp;

pair<ll,ll> f(ll x, ll y) {
    ll len = y - x - 1;
    ll cnt = len / 2;
    ll num = (len % 2 == 0) ? 1 : (len + 1) / 2;
    return { cnt, num };
}

ll power(ll x, ll p) {
    ll res = 1;
    for (ll i = p; i; i >>= 1) {
        if (i & 1) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

int main() {
    FastIO

    cin >> r >> c >> k;

    ll num_row = 0;
    for (ll i = 0; i < k; i++) {
        ll x, y; cin >> x >> y;
        if (!mp.count(x)) mp[x] = num_row++;

        ll idx = mp[x];
        dat[idx].emplace_back(y);
    }

    ll cnt = 0, num = 1;

    for (ll i = 0; i < num_row; i++) {
        assert(!dat[i].empty());
        sort(dat[i].begin(), dat[i].end());

        auto [c0, n0] = f(0, dat[i][0]);
        cnt += c0;
        num = num * n0 % MOD;
        
        for (size_t j = 0; j < dat[i].size(); j++) {
            ll x = dat[i][j];
            ll y = (j + 1u) < dat[i].size() ? dat[i][j + 1u] : c + 1LL;
            auto [c1, n1] = f(x, y);

            cnt += c1;
            num = num * n1 % MOD;
        }
    }

    auto [c2, n2] = f(0, c + 1);
    c2 *= (r - num_row);
    n2 = power(n2, r - num_row);

    cnt += c2;
    num = num * n2 % MOD;
    cout << cnt << ' ' << num << '\n';

    return 0;
}
