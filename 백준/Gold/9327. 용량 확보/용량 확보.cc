#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 200001;

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

        bitset<MAX> dp;
        dp[0] = 1;
        for (int x : arr) dp |= (dp << x);

        int ans = -1;
        for (int i = 0; i <= sum && ans < 0; i++) {
            if (dp[i] && i * 2 >= e) ans = i;
        }

        if (ans >= 0) cout << ans << '\n';
        else cout << "FULL" << '\n';
    }

    return 0;
}
