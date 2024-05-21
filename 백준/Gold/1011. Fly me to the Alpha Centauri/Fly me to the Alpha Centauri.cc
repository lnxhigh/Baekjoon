#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N;
ll x, y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        
        ll d = y - x;
        ll k = floor(sqrt(d));
        
        ll res;
        if (d == k*k) res = 2LL*k - 1LL;
        else if (d <= k*(k+1)) res = 2LL*k;
        else if (d < (k+1)*(k+1)) res = 2LL*k + 1LL;

        cout << res << '\n';
    }

    return 0;
}
