#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int n, m;
int arr[MAX];
int dp[MAX][MAX];

int dfs(int i, int x) {
    int& ret = dp[i][x];
    if (ret != -1) return ret; 
    
    if (i == n) return ret = 0;
    else if (x == m) return ret = dfs(i + 1, m - arr[i]);

    ret = x * x + dfs(i, m);
    if (x > arr[i]) ret = min(ret, dfs(i + 1, x - arr[i] - 1));

    return ret;
}

int main() {
    FastIO
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    memset(dp, -1, sizeof(dp));
    int ans = dfs(0, m);

    cout << ans << '\n';
    return 0;
}
