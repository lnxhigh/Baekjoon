#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

ll f(ll x) {
    ll ret = 0;
    ll amt[4] = { 1000000, 10000, 100, 0 };
    ll price[4] = { 7, 5, 3, 2 };

    for (int i = 0; i < 4 && x; i++) {
        ll diff = x - amt[i];
        if (diff <= 0) continue;

        ret += diff * price[i];
        x -= diff;
    }

    return ret;
}

ll inv(ll x) {
    ll ret = 0;
    ll lo = 0, hi = x;

    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (f(mid) <= x) ret = mid, lo = mid + 1;
        else hi = mid - 1;
    }
    
    return ret;
}

ll solve(ll a, ll b) {
    ll total = inv(a);
    ll lo = 0, hi = total / 2;

    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll other = total - mid;

        ll x = f(other) - f(mid);
        if (x > b) lo = mid + 1;
        else if (x < b) hi = mid - 1;
        else return f(mid);
    }

    return 0;
}

int main() {
    FastIO
    ll a, b;

    while (true) {
        cin >> a >> b;
        if (!a || !b) break;
        
        ll ans = solve(a, b);
        cout << ans << '\n';
    }

    return 0;
}
