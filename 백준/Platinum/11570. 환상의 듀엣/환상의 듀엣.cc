#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 11;
const int INF = 0x7fffffff;

int n;
int arr[MAX];
int dp[MAX][MAX];
int ans = INF;

int dfs(int i, int j) {
    int& ret = dp[i][j];
    if (ret != -1) return ret;
    else if (i + j == 1) return ret = 0;

    if (i < j - 1) {
        ret = dfs(i, j - 1) + abs(arr[j] - arr[j - 1]);
    }
    else if (i == j - 1) {
        ret = INF;
        int sum = 0;

        for (int x = 0; x < i; x++) {
            sum += abs(arr[x] - arr[x + 1]);
            ret = min(ret, dfs(x, i) + abs(arr[j] - arr[x]));
        }
        ret = min(ret, sum);
    }

    return ret;
}

int main() {
    FastIO

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n <= 2) {
        ans = 0;
    }
    else {
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n - 1; i++) {
            ans = min(ans, dfs(i, n - 1));
        }
    }
    
    cout << ans << '\n';
    return 0;
}
