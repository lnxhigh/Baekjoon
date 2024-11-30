#include <bits/stdc++.h>
using namespace std;

int T, K;
pair<int,int> A[101];
int D[101][10001];

int dfs(int k, int t) {
    if (k < 0) return t == 0;
    
    if (D[k][t] != -1) return D[k][t];
    else if (t == 0) return D[k][t] = 1;

    int cnt = 0;
    auto [p, n] = A[k];

    for (int i = 0; i <= n; i++) {
        if (t < p * i) break;

        cnt += dfs(k - 1, t - p * i);
    }

    return D[k][t] = cnt;
}

int main() {
    cin >> T >> K;
    for (int i = 0; i < K; i++) {
        int p, n; cin >> p >> n;
        A[i] = { p, n };
    }

    memset(D, -1, sizeof(D));
    int ans = dfs(K - 1, T);
    cout << ans << '\n';
    return 0;
}
