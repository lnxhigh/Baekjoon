#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

int main() {
    FastIO
    ll n; cin >> n;
    ll ans = 35;

    for (ll i = 2; i <= n; i++) {
        ans += 56;
        ans += 14;
        ans += (i - 2) * 7 * 2;
        ans += (i - 2) * 21;
    }

    cout << ans << '\n';
    return 0;
}
