#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 9;

int n;
int arr[MAX][MAX];
int vis[MAX][MAX];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

int bfs(int x, int y, int t) {
    int cnt = 0;
    
    queue<int> q;
    q.push(n * x + y);
    vis[x][y] = t;

    while (!q.empty()) {
        int k = q.front();
        int x = k / n, y = k % n;
        q.pop();

        cnt++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            else if (abs(arr[nx][ny] - arr[x][y]) > t || vis[nx][ny] == t) continue;

            q.push(n * nx + ny);
            vis[nx][ny] = t;
        }
    }

    return cnt;
}

int main() {
    FastIO

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    int lo = 0, hi = 1'000'000;
    
    int m = (n & 1) ? (n * n + 1) / 2 : (n * n) / 2;
    memset(vis, -1, sizeof(vis));

    while (lo <= hi) {
        int t = (lo + hi) / 2;
        bool chk = false;

        for (int x = 0; x < n && !chk; x++) {
            for (int y = 0; y < n && !chk; y++) {
                if (vis[x][y] == t) continue;
                
                int cnt = bfs(x, y, t);
                chk |= (cnt >= m);
            }
        }

        if (chk) ans = t, hi = t - 1;
        else lo = t + 1;
    }
    
    cout << ans << '\n';

    return 0;
}
