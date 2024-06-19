#include <bits/stdc++.h>
using namespace std;

int R, C;
const int R_MAX = 500, C_MAX = 500;
int Terrain[R_MAX][C_MAX];

int D[R_MAX][C_MAX];
int dr[4] = { -1, +1, 0, 0 };
int dc[4] = { 0, 0, -1, +1 };

int dfs(int x, int y) {
    if (D[x][y] != -1) return D[x][y];

    int res = 0;
    for (int i = 0; i < 4; i++) {
        int nextX = x + dr[i];
        int nextY = y + dc[i];
        if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C) continue;

        if (Terrain[x][y] < Terrain[nextX][nextY]) {
            res += dfs(nextX, nextY);
        }
    }

    return D[x][y] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> Terrain[i][j];
        }
    }
    
    memset(D, -1, sizeof(D));
    D[0][0] = 1;
    int res = dfs(R-1, C-1);
    cout << res << '\n';

    return 0;
}
