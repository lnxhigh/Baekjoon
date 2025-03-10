#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 401;

int N;
int X, Y;

int A[2][MAX];
int S[2][MAX];

int D[MAX][MAX][MAX];
bool V[MAX][MAX][MAX];

int dfs(int i, int x, int y) {
    if (i == 0 || i == x || i == y) return 0;
    
    if (V[i][x][y]) return D[i][x][y];
    V[i][x][y] = true;

    int ret = dfs(i - 1, x, y) + S[0][i - x] * S[1][i - y];
    if (x > 0) ret = max(ret, dfs(i - 1, x - 1, y));
    if (y > 0) ret = max(ret, dfs(i - 1, x, y - 1));
    if (x > 0 && y > 0) ret = max(ret, dfs(i - 1, x - 1, y - 1));

    return D[i][x][y] = ret;
}

int main() {
    FastIO
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[0][i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> A[1][i];
    }

    for (int i = 1, cnt = 0; i <= N; i++) {
        if (A[0][i] == 0) X++;
        else S[0][++cnt] = A[0][i];
    }
    for (int i = 1, cnt = 0; i <= N; i++) {
        if (A[1][i] == 0) Y++;
        else S[1][++cnt] = A[1][i];
    }

    int ans = dfs(N, X, Y);
    cout << ans << '\n';
    return 0;
}
