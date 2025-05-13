#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

ll n, k;
deque<pair<int,ll>> dq;

int main() {
    FastIO

    cin >> n >> k;

    ll sum = 0;
    ll mn = INF;

    for (int i = 0; i <= n; i++) {
        ll x = 0; 
        if (i) cin >> x;
        sum += x;

        ll now = x;
        if (!dq.empty()) now += dq.front().second;
        if (i + k >= n) mn = min(mn, now);
        
        while (!dq.empty() && dq.front().first + k < i) dq.pop_front();
        while (!dq.empty() && dq.back().second >= now) dq.pop_back();
        dq.push_back({ i, now });
    }

    ll ans = sum - mn;
    cout << ans << '\n';
    
    return 0;
}
