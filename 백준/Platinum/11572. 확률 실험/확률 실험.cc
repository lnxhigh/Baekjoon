#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

ll n, r;
bool phi[360000];
ll sum[360000];

int main() {
    FastIO

    cin >> n >> r;
    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;
        phi[x] = true;
    }

    sum[0] = phi[0];
    for (ll i = 1; i < 360000; i++) {
        sum[i] = sum[i - 1];
        if (phi[i]) sum[i]++;
    }

    ll ans = n * (n - 1) * (n - 2) / 6;

    for (ll i = 0; i < 360000; i++) {
        if (!phi[i]) continue;
        ll j = (i + 180000) % 360000;

        ll x = (j > i) ? sum[j] - sum[i] : n - (sum[i] - sum[j]);
        ll cnt = x * (x - 1) / 2;
        ans -= cnt;
    }

    cout << ans << '\n';

    return 0;
}
