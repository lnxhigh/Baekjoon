#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

ll n;
priority_queue<ll> lo, hi;
ll cur = 0, sum = 0;

int main() {
    FastIO
    cin >> n;

    for (ll i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;

        if (i == 0 || y <= cur) lo.push(y);
        else hi.push(-y);

        while (lo.size() > hi.size() + 1u) hi.push(-lo.top()), lo.pop();
        while (lo.size() < hi.size()) lo.push(-hi.top()), hi.pop();
        
        ll nxt = lo.top();

        sum += abs(x);
        if (i == 0 || nxt >= cur) sum += abs(y - nxt);
        else sum += abs(y - cur);
        
        cur = nxt;
        cout << cur << ' ' << sum << '\n';
    }

    return 0;
}
