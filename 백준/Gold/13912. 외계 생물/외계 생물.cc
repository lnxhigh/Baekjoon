#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1'000'000'007;

ll C[2048][2048];
ll D[11];

ll choose(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    else if (k == 0 || k == n) return 1;
    if (C[n][k]) return C[n][k];
    
    k = min(k, n - k);
    ll x = choose(n - 1, k);
    ll y = choose(n - 1, k - 1);
    return C[n][k] = (x + y) % MOD;
}

int main() {
    ll H; cin >> H;

    D[0] = 1;
    for (int h = 1; h <= H; h++) {
        ll all = (1 << (h + 1)) - 1;
        ll sel = choose(all - 1, (all - 1) >> 1);
        ll cnt = D[h - 1] * D[h - 1] % MOD;
        
        D[h] = sel * cnt % MOD;
    }

    cout << D[H] << '\n';
    return 0;
}
