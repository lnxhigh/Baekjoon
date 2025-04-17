#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const ll MOD = 1'000'000'007;

int main() {
    FastIO
    
    ll n; cin >> n;
    ll r = n % 4;

    ll mul = 1;
    for (ll i = 0; i < r; i++) {
        mul *= (n - i);
        mul /= (i + 1);
    }

    ll cur = 0, prv = 1;

    for (ll i = 1; i < n - r; i++) {
        ll nxt = i * (cur + prv) % MOD;
        prv = cur, cur = nxt;
    }

    ll ans = cur * mul % MOD;
    cout << ans << '\n';

    return 0;
}
