#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

int main() {
    FastIO

    ll n, q; cin >> n >> q;
    vector<pair<ll,ll>> arr(n + 1);
    vector<ll> sum(n + 1), wsum(n + 1);

    for (ll i = 1; i <= n; i++) {
        auto& [x, a] = arr[i];
        cin >> a >> x;
    }

    sort(arr.begin() + 1, arr.end());

    for (ll i = 1; i <= n; i++) {
        auto [x, a] = arr[i];
        sum[i] = sum[i - 1] + a;
        wsum[i] = wsum[i - 1] + a * x;
    }

    while (q--) {
        ll x; cin >> x;
        
        ll idx = 0;
        ll lo = 1, hi = n;

        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            if (arr[mid].first <= x) idx = mid, lo = mid + 1;
            else hi = mid - 1;
        }

        ll l = x * sum[idx] - wsum[idx];
        ll r = (wsum[n] - wsum[idx]) - x * (sum[n] - sum[idx]);

        cout << l + r << '\n';
    }

    return 0;
}
