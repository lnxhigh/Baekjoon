#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;
const int MOD = 10'007;

string S;
int D[MAX][MAX];

int dfs(int x, int y) {
    if (D[x][y] != -1) return D[x][y];
    if (x > y) return D[x][y] = 0;
    else if (x == y) return D[x][y] = 1;

    D[x][y] = dfs(x, y - 1) + dfs(x + 1, y) - dfs(x + 1, y - 1) + MOD;
    if (S[x] == S[y]) D[x][y] += dfs(x + 1, y - 1) + 1;
    D[x][y] %= MOD;
    
    return D[x][y];
}

int main() {
    FastIO
    
    cin >> S;
    int L = S.size();
    memset(D, -1, sizeof(D));

    int ans = dfs(0, L - 1);
    cout << ans << '\n';

    return 0;
}
