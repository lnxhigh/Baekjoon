#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int n, m;
int arr[10][10];

int dist[10][10][2];
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

bool check(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        int rx = x + dx[(i + 1) % 4], ry = y + dy[(i + 1) % 4];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (rx < 0 || rx >= n || rx < 0 || rx >= n) continue;
        if (arr[nx][ny] != 1 && arr[rx][ry] != 1) return false;
    }

    return true;
}

int dijkstra() {
    int ret = 1e9;

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            for (int k = 0; k <= 1; k++) 
                dist[i][j][k] = 1e9;
    
    priority_queue<tuple<int,int,bool>> pq;
    pq.push({ 0, 0, false });
    dist[0][0][0] = 0;

    while (!pq.empty()) {
        auto [t, k, f] = pq.top();
        t = -t;
        pq.pop();

        int x = k / n, y = k % n;
        if (x == n - 1 && y == n - 1) ret = min(ret, t);
        if (dist[x][y][f] < t) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            else if (arr[x][y] != 1 && arr[nx][ny] != 1) continue;
            else if (arr[nx][ny] == 0 && (f || !check(nx, ny))) continue;

            int p = 0;
            bool add = false;

            if (arr[nx][ny] == 0) p = m, add = true;
            else p = arr[nx][ny], add = false;
            
            int nt = ((t + 1) % p) ? (t + 1) / p * p + p : (t + 1);
            bool nf = f | add;
            
            if (nt < dist[nx][ny][nf]) {
                dist[nx][ny][nf] = nt;
                pq.push({ -nt, nx * n + ny, nf });
            }
        }
    }

    return ret;
}

int main() {
    FastIO

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = dijkstra();
    cout << ans << '\n';

    return 0;
}
