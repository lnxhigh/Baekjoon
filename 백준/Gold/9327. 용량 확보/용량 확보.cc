#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO
    int tc; cin >> tc;
    while (tc--) {
        int n, e; cin >> n >> e;
        
        vector<int> arr(n);
        for (int& x : arr) cin >> x;

        int sum = 0;
        for (int& x : arr) sum += x;

        if (sum * 2 < e) {
            cout << "FULL" << '\n';
            continue;
        }

        vector<bool> dp(sum + 1);
        dp[0] = true;

        for (int& x : arr) {
            for (int i = sum - x; i >= 0; --i) {
                if (dp[i]) dp[i + x] = true;
            }
        }

        int ans = -1;
        for (int i = 0; i <= sum && ans == -1; i++) {
            if (dp[i] && i * 2 >= e) ans = i;
        }

        if (ans >= 0) cout << ans << '\n';
        else cout << "FULL" << '\n';
    }

    return 0;
}
