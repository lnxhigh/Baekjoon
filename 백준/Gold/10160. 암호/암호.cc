#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAX = 1 << 20;
const ll MOD = 1e9 + 9;

ll dp[MAX];

int main() {
    ll n, k; cin >> n >> k;

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] * k % MOD;
        if (i >= 5) dp[i] = (dp[i] - dp[i - 5] - dp[i - 5] + MOD + MOD) % MOD;
        if (i >= 7) dp[i] = (dp[i] + dp[i - 7]) % MOD;
    }
    
    cout << dp[n] << '\n';
    return 0;
}
