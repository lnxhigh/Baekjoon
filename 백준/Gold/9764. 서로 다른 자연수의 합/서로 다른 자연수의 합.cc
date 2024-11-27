#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 11;
const int MOD = 100999;

int D[MAX][MAX];

int dfs(int n, int k) {
    int& ret = D[n][k];
    if (ret != -1) return ret;
    if (k == 0) return ret = 1;

    int cnt = 0;
    for (int i = 1; i <= min(n, k); i++) {
        cnt += dfs(i - 1, k - i);
        cnt %= MOD;
    }
    
    return ret = cnt;
}

int main() {
    FastIO
    memset(D, -1, sizeof(D));

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        int ans = dfs(N, N);
        cout << ans << '\n';
    }

    return 0;
}
