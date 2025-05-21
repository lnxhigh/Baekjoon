#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

ll dp[21][21][21];

int main() {
    FastIO

    dp[0][0][0] = 1;

    for (int n = 1; n <= 20; n++) {
        for (int l = 1; l <= n; l++) {
            for (int r = 1; r <= n; r++) {
                for (int t = 0, mul = 1; t < n; t++) {
                    ll x = 0, y = 0;
                    for (int i = 0; i <= t; i++) {
                        x += dp[t][l - 1][i];
                    }
                    for (int i = 0; i <= n - 1 - t; i++) {
                        y += dp[n - 1 - t][i][r - 1];
                    }

                    dp[n][l][r] += x * y * mul;
                    mul = mul * (n - 1 - t) / (t + 1);
                }
            }
        }
    }

    int tc; cin >> tc;
    while (tc--) {
        int n, l, r; cin >> n >> l >> r;
        cout << dp[n][l][r] << '\n';
    }

    return 0;
}
