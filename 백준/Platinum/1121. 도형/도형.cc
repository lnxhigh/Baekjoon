#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAX = 50002;

ll n, k;
ll arr[50];
ll dp[11][MAX];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> k;

    ll ans = 0;
    dp[0][0] = 1;
    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        for (ll p = arr[i] + 1; p < MAX; p++) {
            ans += dp[k - 1][p];
        }

        for (int x = k; x >= 1; x--) {
            for (ll p = MAX - 1; p >= MAX - 1 - arr[i]; p--) {
                dp[x][MAX - 1] += dp[x - 1][p];
            }
            for (ll p = MAX - 2; p >= arr[i]; p--) {
                dp[x][p] += dp[x - 1][p - arr[i]];
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
