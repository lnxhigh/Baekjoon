#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 5000;

int n, w;
int arr[MAX];
bitset<800001> dp[5];

int main() {
    FastIO

    cin >> w >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int k = 4; k; k--) {
            dp[k] |= dp[k - 1] << arr[i];
        }
    }
    
    string ans = dp[4][w] ? "YES" : "NO";
    cout << ans << '\n';
    return 0;
}
