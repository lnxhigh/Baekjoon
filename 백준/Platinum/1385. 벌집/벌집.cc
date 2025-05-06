#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int a, b;
int sx, sy, ex, ey;

int arr[1200][2400];
int dx[6] = { 1,  1,  0, -1, -1, 0 };
int dy[6] = { 1, -1, -2, -1,  1, 2 };

int pre[1200 * 2400];
bool vis[1200][2400];

int main() {
    FastIO
    cin >> a >> b;

    int num = 1;
    int x = 600, y = 1200;

    // num == 1

    if (num == a) sx = x, sy = y;
    if (num == b) ex = x, ey = y;
    arr[x][y] = num++;

    // num > 1

    for (int h = 1; h < 595; h++) {
        x += dx[5], y += dy[5];
        for (int dir = 0; dir < 6; dir++) {
            for (int i = 0; i < h; i++) {
                if (num == a) sx = x, sy = y;
                if (num == b) ex = x, ey = y;
                arr[x][y] = num++;
                x += dx[dir], y += dy[dir];
            }
            x -= dx[dir], y -= dy[dir];
            x += dx[(dir + 1) % 6], y += dy[(dir + 1) % 6];
        }

        x -= dx[0], y -= dy[0];
    }

    queue<int> q;
    q.push(sx * 2400 + sy);
    vis[sx][sy]= true;

    while (!q.empty()) {
        int t = q.front();
        int x = t / 2400, y = t % 2400;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (arr[nx][ny] == 0 || vis[nx][ny]) continue;

            int nxt = nx * 2400 + ny;
            q.push(nxt);
            pre[nxt] = t;
            vis[nx][ny] = true;
        }
    }
    
    stack<int> path;
    for (int i = ex * 2400 + ey; i > 0; i = pre[i]) {
        int x = i / 2400, y = i % 2400;
        int num = arr[x][y];
        path.push(num);
    }

    while (!path.empty()) cout << path.top() << ' ', path.pop();
    cout << '\n';
    
    return 0;
}
