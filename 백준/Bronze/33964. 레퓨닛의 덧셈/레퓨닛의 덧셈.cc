#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

ll f(int n) {
    ll mul = 1;
    while (n--) mul *= 10LL;
    return (mul - 1LL) / 9LL;
}

int main() {
    FastIO
    ll x, y; cin >> x >> y;
    ll ans = f(x) + f(y);
    cout << ans << '\n';

    return 0;
}
