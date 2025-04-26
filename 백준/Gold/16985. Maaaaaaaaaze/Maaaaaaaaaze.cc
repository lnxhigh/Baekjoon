#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

const int n = 5;
bool cube[n][n][n];
bool vis[n][n][n];

int ans = -1;
int dx[6] = { -1, +1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, +1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, +1 };

vector<int> match = { 0, 1, 2, 3, 4 };

void input() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> cube[k][i][j];
            }
        }
    }
}

void rotate(bool arr[5][5]) {
    bool tmp[5][5];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = arr[j][n - 1 - i];
        }
    }

    memcpy(arr, tmp, sizeof(tmp));
}

int bfs(int x, int y, int z) {
    if (!cube[match[x]][y][z]) return -1;

    queue<tuple<int,int,int,int>> q;
    q.push({ x, y, z, 0 });
    
    memset(vis, false, sizeof(vis));
    vis[x][y][z] = true;

    while (!q.empty()) {
        auto [cx, cy, cz, cnt] = q.front();
        q.pop();

        if (x + cx + 1 == n && y + cy + 1 == n && z + cz + 1 == n) return cnt;

        for (int i = 0; i < 6; i++) {
            int nx = cx + dx[i], ny = cy + dy[i], nz = cz + dz[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || nz < 0 || nz >= n) continue;
            else if (!cube[match[nx]][ny][nz] || vis[nx][ny][nz]) continue;

            q.push({ nx, ny, nz, cnt + 1 });
            vis[nx][ny][nz] = true;
        }
    }

    return -1;
}

void dfs(int depth) {
    if (depth == 5) {
        int cnt = bfs(0, 0, 0);

        if (cnt != -1) {
            ans = (ans != -1) ? min(ans, cnt) : cnt;
        }

        return;
    }

    for (int i = 0; i < 4; i++) {
        dfs(depth + 1);
        rotate(cube[depth]);
    }
}

int main() {
    FastIO
    input();

    do {
        dfs(0);
    } while (next_permutation(match.begin(), match.end()));

    cout << ans << '\n';
    return 0;
}
