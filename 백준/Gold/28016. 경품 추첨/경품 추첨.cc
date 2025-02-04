#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 7;

int R, C;
int A[MAX][MAX];
__int128 D[MAX][MAX];

__int128 dfs(int x, int y) {
    if (D[x][y] != -1) return D[x][y];
    if (x == 0) return D[x][y] = (A[x][y] == 2) ? (__int128) 1 << R : 0;
    else if (A[x][y] == 1 || A[x - 1][y] == 1) return D[x][y] = 0;

    D[x][y] = dfs(x - 1, y);
    if (y > 0 && A[x][y - 1] == 1) {
        D[x][y] += dfs(x - 1, y - 1) >> 1;
    }
    if (y < C - 1 && A[x][y + 1] == 1) {
        D[x][y] += dfs(x - 1, y + 1) >> 1;
    }

    return D[x][y];
}

int main() {
    FastIO
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> A[i][j];
        }
    }
    
    memset(D, -1, sizeof(D));
    vector<__int128> P(C);
    for (int i = 0; i < C; i++) {
        P[i] = dfs(R - 1, i);
    }
    
    auto iter = max_element(P.begin(), P.end());
    if (*iter == 0) cout << -1 << '\n';
    else cout << (iter - P.begin()) << '\n';
    return 0;
}
