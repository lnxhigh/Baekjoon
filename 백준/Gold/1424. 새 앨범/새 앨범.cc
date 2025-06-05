#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100'001;

int n, l, c;
int dp[MAX];

int main() {
    FastIO
    
    cin >> n >> l >> c;
    iota(dp, dp + MAX, 0);

    for (int i = 1; i <= n; i++) {
        int m = min(i, 1 + (c - l) / (1 + l));
        for (int x = 1; x <= m; x++) {
            if (x % 13) dp[i] = min(dp[i], dp[i - x] + 1);
        }
    }

    cout << dp[n] << '\n';
    return 0;
}
