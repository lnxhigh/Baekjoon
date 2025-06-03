#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

ll f(ll x, ll h, ll i) {
    if (h == 1 || (i + 1 == (1LL << h))) return x;
    if (i & 1) return f((x << 1) + (x & 1), h - 1, (i / 2) + 1);
    else return f((x << 1) + (~x & 1), h - 1, (i / 2));
}

int main() {
    FastIO
    ll n, q, k;
    cin >> n >> q;
    while (q--) cin >> k, cout << f(1, n, k) << '\n';
    return 0;
}
