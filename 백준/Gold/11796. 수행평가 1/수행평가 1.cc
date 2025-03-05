#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const ll MAX = 100'001;
const ll MOD = 1'000'000'007;

ll N, M;
ll A[MAX];

ll check(ll len) {
    set<vector<ll>> s;
    vector<ll> vec;

    for (ll i = 0; i < len; i++) {
        vec.push_back(A[i]);
    }
    s.insert(vec);

    for (ll i = 0; i + len < N; i++) {
        vec.erase(vec.begin());
        vec.push_back(A[i + len]);
        s.insert(vec);
    }
    
    ll total = 1;
    for (ll i = 0; i < len; i++) total *= M;

    ll cnt = s.size();

    return total - cnt;
}

int main() {
    FastIO
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];

    if (M == 1) {
        cout << N + 1 << ' ' << 1 << '\n';
        return 0;
    }

    ll lo = 1, hi = 0;

    ll len = 0, mul = 1;
    while (mul <= N - len + 1) len++, mul *= M;
    hi = min(len, N);

    ll ans = N, cnt = 1;

    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll diff = check(mid);

        if (diff > 0) ans = mid, cnt = diff % MOD, hi = mid - 1;
        else lo = mid + 1;
    }

    cout << ans << ' ' << cnt << '\n';
    return 0;
}
