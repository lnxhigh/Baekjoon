#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

ll f(ll n, ll x, ll m) {
    return (n / x) * m + min(m, n % x);
}

ll solve(ll n) {
    ll sum = 0;

    for (ll mul = 1; mul <= n; mul *= 10) {
        for (ll i = 1; i < 10; i++) {
            ll x = f(n, mul * 10, mul * (i + 1));
            ll y = f(n, mul * 10, mul * i);
            sum += (x - y) * i;
        }
    }

    return sum;
}

int main() {
    FastIO
    ll L, U; cin >> L >> U;
    ll ans = solve(U + 1) - solve(L);
    cout << ans << '\n';
    return 0;
}
