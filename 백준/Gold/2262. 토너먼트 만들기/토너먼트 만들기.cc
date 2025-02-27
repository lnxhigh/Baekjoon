#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = (1 << 8) + 1;
const int INF = 1 << 28;

int N;
int R[MAX];

int D[MAX][MAX];
int M[MAX][MAX];

int win(int x, int y) {
    if (x == y) return R[x];
    if (M[x][y]) return M[x][y];

    int k = (x + y) / 2;
    return M[x][y] = min(win(x, k), win(k + 1, y));
}

int dfs(int x, int y) {
    if (x == y) return 0;
    if (D[x][y]) return D[x][y];

    D[x][y] = INF;
    for (int k = x; k < y; k++) {
        int diff = abs(win(x, k) - win(k + 1, y));
        D[x][y] = min(D[x][y], dfs(x, k) + dfs(k + 1, y) + diff);
    }

    return D[x][y];
}

int main() {
    FastIO
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> R[i];
    }

    int ans = dfs(1, N);
    cout << ans << '\n';
    return 0;
}
