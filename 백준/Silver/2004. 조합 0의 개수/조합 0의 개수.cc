#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t(ll x) {
    ll cnt = 0;
    for (ll i = 2; i <= x; i *= 2) cnt += x / i;
    return cnt;
}

ll f(ll x) {
    ll cnt = 0;
    for (ll i = 5; i <= x; i *= 5) cnt += x / i;
    return cnt;
}

int main() {
    ll N, K; cin >> N >> K;

    ll two  = t(N) - t(K) - t(N - K);
    ll five = f(N) - f(K) - f(N - K);
    
    ll ans = min(two, five);
    cout << ans << '\n';
    return 0;
}
