#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const int MAX = 41;

ll n, k;
ll f[MAX], dp[MAX];

int main() {
    FastIO
    cin >> n >> k;

    f[0] = f[1] = 1;
    for (int i = 2; i < MAX; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + f[i] + f[i - 1] - 2;
    }

    ll ans = dp[n - k + 1] * f[k - 1] + dp[k] * f[n - k] - f[k - 1] * f[n - k];
    cout << ans << '\n';
    
    return 0;
}
