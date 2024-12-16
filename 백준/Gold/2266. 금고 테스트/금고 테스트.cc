#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 9;

int N, K;
int D[MAX][MAX];

int dfs(int n, int k) {
    if (D[n][k] != -1) return D[n][k];
    if (n == 0) return D[n][k] = 0;
    else if (k == 1) return D[n][k] = n;

    int ret = n;
    for (int i = 1; i <= n; i++) {
        int dead  = dfs(i - 1, k - 1);
        int alive = dfs(n - i, k);

        int cnt = max(dead, alive) + 1;
        ret = min(ret, cnt);
    }

    return D[n][k] = ret;
}

int main() {
    FastIO
    memset(D, -1, sizeof(D));
    cin >> N >> K;
    cout << dfs(N, K) << '\n';
    return 0;
}
