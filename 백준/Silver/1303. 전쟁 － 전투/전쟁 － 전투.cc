#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
#define For(i, n) for (int i = 0; i < n; i++)
using namespace std;

int R, C;
const int MAX = 1 << 7;
char field[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

int dfs(int x, int y, char color) {
    visited[x][y] = true;

    int res = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if (visited[nx][ny] || field[nx][ny] != color) continue;
        res += dfs(nx, ny, color);
    }

    return res;
}

int main() {
    FastIO
    cin >> C >> R;
    For (r, R) {
        For (c, C) {
            cin >> field[r][c];
        }
    }

    int white = 0, blue = 0;
    For (r, R) {
        For (c, C) {
            if (visited[r][c]) continue;
            
            char color = field[r][c];
            int res = dfs(r, c, color);
            int &X = (color == 'W') ? white : blue;
            X += res * res;
        }
    }

    cout << white << ' ' << blue << '\n';
    return 0;
}
