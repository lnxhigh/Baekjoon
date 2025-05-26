#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll phi(ll x) {
    ll ret = x;

    for (ll i = 2; i * i <= x && x > 1; i++) {
        if (x % i != 0) continue;
        while (x % i == 0) x /= i;
        ret = ret * (i - 1) / i;
    }

    if (x > 1) ret = ret * (x - 1) / x;
    return ret;
}

int main() {
    ll n; cin >> n;

    ll ans = 0;
    while (n) ans += phi(n--);
    cout << --ans << '\n';

    return 0;
}
