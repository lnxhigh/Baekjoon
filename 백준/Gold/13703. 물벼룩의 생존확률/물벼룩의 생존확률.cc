#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int MAX = 1 << 7;

int64 D[MAX][MAX];

int64 dfs(int k, int n) {
    if (D[k][n] != -1) return D[k][n];
    
    if (k == 0) return D[k][n] = 0;
    else if (n == 0) return D[k][n] = 1;
    
    return D[k][n] = dfs(k + 1, n - 1) + dfs(k - 1, n - 1);
}

int main() {
    FastIO
    memset(D, -1, sizeof(D));
    int k, n; cin >> k >> n;
    int64 ans = dfs(k, n);
    cout << ans << '\n';
    return 0;
}
