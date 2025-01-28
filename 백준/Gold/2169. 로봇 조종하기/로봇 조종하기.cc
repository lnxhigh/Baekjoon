#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;
const int INF = 1 << 27;

int R, C;
int A[MAX][MAX];

enum Direction { LEFT, RIGHT, UP };
int D[MAX][MAX][3];
bool V[MAX][MAX][3];

int dfs(int x, int y, Direction dir) {
    if (x < 0 || x >= R || y < 0 || y >= C) return -INF;
    else if (V[x][y][dir]) return D[x][y][dir];
    else if (x == 0 && y == 0) return A[x][y];

    if (dir == LEFT) D[x][y][dir] = max(dfs(x, y - 1, dir), dfs(x, y - 1, UP));
    else if (dir == RIGHT) D[x][y][dir] = max(dfs(x, y + 1, dir), dfs(x, y + 1, UP));
    else D[x][y][dir] = max({ dfs(x - 1, y, LEFT), dfs(x - 1, y, RIGHT), dfs(x - 1, y, UP) });

    V[x][y][dir] = true;
    D[x][y][dir] += A[x][y];
    return D[x][y][dir];
}

int main() {
    FastIO
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> A[i][j];
        }
    }

    int ans = max(dfs(R - 1, C - 1, LEFT), dfs(R - 1, C - 1, UP));
    cout << ans << '\n';
    return 0;
}
