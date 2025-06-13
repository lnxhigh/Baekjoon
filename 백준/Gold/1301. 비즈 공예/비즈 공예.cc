#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

ll n;
ll arr[5];

ll total = 0;
ll dp[11][11][11][11][11][5][5];

ll dfs(ll* x, ll cnt, ll prv, ll cur) {
    ll& ret = dp[x[0]][x[1]][x[2]][x[3]][x[4]][prv][cur];
    if (ret != -1) return ret;
    else if (cnt == total) return ret = 1;

    ll sum = 0;
    ll tmp[5] = {0};
    memcpy(tmp, x, sizeof(arr));

    for (ll nxt = 0; nxt < n; nxt++) {
        if (nxt == prv || nxt == cur || !tmp[nxt]) continue;
        tmp[nxt]--;
        sum += dfs(tmp, cnt + 1, cur, nxt);
        tmp[nxt]++;
    }
    
    return ret = sum;
}

int main() {
    FastIO

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    
    ll ans = 0;
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            arr[i]--, arr[j]--;
            ans += dfs(arr, 2, i, j);
            arr[i]++, arr[j]++;
        }
    }

    cout << ans << '\n';
    return 0;
}
