#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

ll n, t, p;
vector<ll> k;

int main() {
    FastIO
    cin >> n >> t >> p;
    k.resize(n);
    for (ll& x : k) cin >> x;

    ll ans = 0, sum = 0;
    priority_queue<ll> pq;

    for (ll i = 0; i < n; i++) {
        if (sum + k[i] <= t) {
            sum += k[i];
            pq.push(k[i]);
        }
        else {
            if (!pq.empty() && pq.top() > k[i]) {
                sum -= (pq.top() - k[i]);
                pq.pop();
                pq.push(k[i]);
            }
        }

        if (sum <= t) ans = max(ans, (ll)pq.size());
        sum += p;
    }

    cout << ans << '\n';
    return 0;
}
