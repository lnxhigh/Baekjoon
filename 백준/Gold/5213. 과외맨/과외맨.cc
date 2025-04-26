#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 505;

int n;
int arr[MAX][MAX << 1];
int num[MAX][MAX << 1];

int dist[MAX][MAX << 1];
int vis[MAX][MAX << 1];
pair<int,int> p[MAX][MAX << 1];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

int main() {
    FastIO
    cin >> n;

    int total = 0;
    int last = 0;

    // input

    for (int row = 1; row <= n; row++) {
        int m = (row & 1) ? n : n - 1;
        int base = (row & 1) ? 1 : 2;

        for (int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            
            int l = base + i * 2;
            int r = base + i * 2 + 1;

            arr[row][l] = x, arr[row][r] = y;
            num[row][l] = num[row][r] = ++total;

            last = r;
        }
    }

    // bfs

    deque<tuple<int,int,int>> q;
    q.push_front({ 1, 1, 1 });
    vis[1][1] = 1;

    while (!q.empty()) {
        auto [x, y, cnt] = q.front();
        q.pop_front();

        dist[x][y] = cnt;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (arr[nx][ny] == 0) continue;

            if (num[nx][ny] == num[x][y] || arr[nx][ny] == arr[x][y]) {
                if (num[nx][ny] == num[x][y]) {
                    if (vis[nx][ny] == 0 || vis[nx][ny] > cnt) {
                        q.push_front({ nx, ny, cnt });
                        vis[nx][ny] = cnt;
                        p[nx][ny] = { x, y };
                    }
                }
                else {
                    if (vis[nx][ny] == 0 || vis[nx][ny] > cnt + 1) {
                        q.push_back({ nx, ny, cnt + 1 });
                        vis[nx][ny] = cnt + 1;
                        p[nx][ny] = { x, y };
                    }
                }
            }
        }
    }

    int ans = 0;
    vector<int> path;

    int x = 0, y = 0;
    
    if (dist[n][last]) {
        ans = dist[n][last];
        x = n, y = last;
    }
    else {
        int tx = 0, ty = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= (n * 2); j++) {
                if (arr[i][j] != 0 && dist[i][j] != 0) {
                    tx = i, ty = j;
                }
            }
        }

        ans = dist[tx][ty];
        x = tx, y = ty;
    }

    while (x != 0 && y != 0) {
        path.push_back(num[x][y]);
        auto [px, py] = p[x][y];
        x = px, y = py;
    }

    reverse(path.begin(), path.end());
    path.erase(unique(path.begin(), path.end()), path.end());
    
    cout << ans << '\n';
    for (int x : path) cout << x << ' ';
    cout << '\n';

    return 0;
}
