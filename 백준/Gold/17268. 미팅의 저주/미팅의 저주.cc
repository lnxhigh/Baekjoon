#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const ll MOD = 987'654'321;

ll D[10'001];

int main() {
    FastIO
    
    ll n; cin >> n;
    D[0] = 1;

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j < i; j++) {
            D[i] += D[j - 1] * D[i - j - 1] % MOD;
        }
        D[i] %= MOD;
    }

    cout << D[n] << '\n';
    return 0;
}
