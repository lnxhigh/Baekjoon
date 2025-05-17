#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int n, m;
int arr[10][10];

bool vis[10][10][2][5000];
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

bool out(int x, int y) {
    return (x < 0 || x >= n || y < 0 || y >= n);
}

bool check(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        int rx = x + dx[(i + 1) % 4], ry = y + dy[(i + 1) % 4];
        
        if (out(nx, ny) || out(rx, ry)) continue;
        if (arr[nx][ny] != 1 && arr[rx][ry] != 1) return false;
    }

    return true;
}

int bfs() {
    queue<tuple<int,int,int>> q;
    q.push({ 0, 0, 0 });
    vis[0][0][0][0] = true;

    while (!q.empty()) {
        auto [k, flag, t] = q.front();
        q.pop();

        int x = k / n, y = k % n;
        if (x == n - 1 && y == n - 1) return t;

        if (t + 1 >= 5000) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (out(nx, ny)) continue;

            if (arr[nx][ny] == 0) {
                if (flag == 0 && (t + 1) % m == 0 && check(nx, ny) && arr[x][y] == 1) {
                    if (!vis[nx][ny][1][t + 1]) {
                        q.push({ nx * n + ny, 1, t + 1 });
                        vis[nx][ny][1][t + 1] = true;
                    }
                }
            }
            else {
                if ((t + 1) % arr[nx][ny] == 0 && (arr[x][y] == 1 || arr[nx][ny] == 1)) {
                    if (!vis[nx][ny][flag][t + 1]) {
                        q.push({ nx * n + ny, flag, t + 1 });
                        vis[nx][ny][flag][t + 1] = true;
                    }
                }
            }
        }
        
        if (arr[x][y] == 1) {
            if (!vis[x][y][flag][t + 1]) {
                q.push({ x * n + y, flag, t + 1 });
                vis[x][y][flag][t + 1] = true;
            }
        }
    }

    return -1;
}

int main() {
    FastIO

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = bfs();
    cout << ans << '\n';

    return 0;
}
