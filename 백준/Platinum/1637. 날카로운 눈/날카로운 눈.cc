#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

ll N;
vector<tuple<ll,ll,ll>> Data;

ll f(ll x) {
    ll cnt = 0;

    for (const auto& [A, B, C] : Data) {
        if (x < A || C < A) continue;
        ll k = (min(x, C) - A) / B;
        cnt += k + 1;
    }

    return cnt;
}

int main() {
    FastIO
    
    cin >> N;
    Data.resize(N);
    for (auto& [A, B, C] : Data) {
        cin >> A >> C >> B;
    }

    ll ans = 0;
    ll low = 1, high = 2'147'483'647;

    while (low <= high) {
        ll mid = (low + high) / 2;
        ll cnt = f(mid);
        if (cnt & 1) ans = mid, high = mid - 1;
        else low = mid + 1;
    }

    ll cnt = 0;
    for (const auto& [A, B, C] : Data) {
        if (ans < A || ans > C) continue;
        if ((ans - A) % B == 0) cnt++;
    }

    if (ans) cout << ans << ' ' << cnt << '\n';
    else cout << "NOTHING" << '\n';
    return 0;
}
