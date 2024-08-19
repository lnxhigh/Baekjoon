#include <bits/stdc++.h>
#define ll long long
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
    FastIO

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        priority_queue<ll,vector<ll>,greater<ll>> pq;
        while (N--) {
            ll C;
            cin >> C;
            pq.push(C);
        }

        ll res = 0;
        while (pq.size() > 1) {
            ll x = pq.top(); pq.pop();
            ll y = pq.top(); pq.pop();
            ll z = x + y;
            
            pq.push(z);
            res += z;
        }

        cout << res << '\n';
    }

    return 0;
}
