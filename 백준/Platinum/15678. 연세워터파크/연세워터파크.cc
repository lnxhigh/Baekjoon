#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

ll n, d;
deque<pair<int,ll>> dq;
ll ans = -(1LL << 60);

int main() {
    FastIO

    cin >> n >> d;

    for (int i = 0; i < n; i++) {
        ll x; cin >> x;

        ll now = x;
        if (!dq.empty() && dq.front().second > 0) now += dq.front().second;
        ans = max(ans, now);
        
        while (!dq.empty() && (dq.front().first + d <= i)) dq.pop_front();
        while (!dq.empty() && (dq.back().second <= now)) dq.pop_back();
        dq.push_back({ i, now });
    }

    cout << ans << '\n';
    return 0;
}
