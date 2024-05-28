#include <bits/stdc++.h>
#define ll long long
#define N_MAX 4000001
#define MOD 1000000007LL
using namespace std;

ll T;
ll remain[N_MAX];

ll power(ll x, ll p) {
    if (p == 1) return x % MOD;
    ll a = power(x, p / 2);
    ll aa = (a * a) % MOD;

    if (p % 2LL == 0LL) return aa;
    else return (x * aa) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;
    remain[0] = 1;
    for (int i = 1; i < N_MAX; i++) {
        remain[i] = (remain[i-1] * (1LL * i)) % MOD;
    }

    for (int i = 0; i < T; i++) {
        ll N, K;
        cin >> N >> K;
        ll x = remain[N];
        ll y = power(remain[K], MOD-2);
        ll z = power(remain[N-K], MOD-2);
        
        ll answer = (x * ( (y*z) % MOD ) ) % MOD;
        cout << answer << '\n';
    }

    return 0;
}
