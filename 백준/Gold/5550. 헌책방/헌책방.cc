#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 11;

int N, K;
int X[11];
int C[11][MAX], D[11][MAX];

int dfs(int g, int k) {
    if (D[g][k] != -1) return D[g][k];
    else if (g == 0 || k == 0) return D[g][k] = 0;

    D[g][k] = dfs(g - 1, k);
    for (int i = 1; i <= min(X[g], k); i++) {
        D[g][k] = max(D[g][k], dfs(g - 1, k - i) + C[g][i - 1] + i * (i - 1));
    }
    
    return D[g][k];
}

int main() {
    FastIO
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int p, g; cin >> p >> g;
        C[g][X[g]++] = p;
    }
    
    for (int g = 1; g <= 10; g++) {
        if (!X[g]) continue;
        
        sort(C[g], C[g] + X[g], [] (int& x, int& y) { return x > y; });
        for (int i = 1; i < X[g]; i++) {
            C[g][i] += C[g][i - 1];
        }
    }

    memset(D, -1, sizeof(D));
    int ans = dfs(10, K);
    cout << ans << '\n';
    return 0;
}
