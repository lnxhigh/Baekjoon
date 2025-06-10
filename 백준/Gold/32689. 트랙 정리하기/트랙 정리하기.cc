#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

ll n;
vector<ll> arr;
vector<ll> sum;

int main() {
    FastIO

    cin >> n;
    arr.resize(n);
    for (ll& x : arr) cin >> x;

    sum.resize(n);
    for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + arr[i];

    ll ans = 0;
    ll tot = sum[n - 1];

    for (int i = 0; i < n; i++) {
        ll cw = tot - sum[i] * 2;
        ll ccw = (tot - 1) - (tot - sum[i]) * 2;
        ans += max(cw, ccw);
    }
    
    cout << ans << '\n';
    return 0;
}
