#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using Point = pair<int,int>;
const int MAX = 1 << 7;

int r, c;
Point a11, a22, b11, b22;

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

bool vis[MAX][MAX];
int tx[MAX][MAX], ty[MAX][MAX];

int bfs(Point src, Point dst, vector<Point> other) {
    memset(vis, false, sizeof(vis));
    memset(tx, -1, sizeof(tx));
    memset(ty, -1, sizeof(ty));

    queue<pair<Point,int>> q;
    q.push({ src, 0 });
    vis[src.first][src.second] = true;
    for (auto [x, y] : other) vis[x][y] = true;

    while (!q.empty()) {
        auto [cur, cnt] = q.front();
        auto [x, y] = cur;
        q.pop();

        if (cur == dst) return cnt;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx > r || ny < 0 || ny > c) continue;
            else if (vis[nx][ny]) continue;
            
            Point nxt = { nx, ny };
            q.push({ nxt, cnt + 1 });
            vis[nx][ny] = true;
            tx[nx][ny] = x, ty[nx][ny] = y;
        }
    }

    return -1;
}

int solve(Point a1, Point a2, Point b1, Point b2) {
    vector<Point> other = { b1, b2 };
    int cnt = bfs(a1, a2, other);

    other.clear();
    auto [x, y] = a2;

    while (x != -1 && y != -1) {
        other.push_back({ x, y });
        int nx = tx[x][y], ny = ty[x][y];
        x = nx, y = ny;
    }

    int add = bfs(b1, b2, other);

    if (cnt < 0 || add < 0) return -1;
    return cnt + add;
}

int main() {
    FastIO
    
    cin >> r >> c;
    cin >> a11.first >> a11.second;
    cin >> a22.first >> a22.second;
    cin >> b11.first >> b11.second;
    cin >> b22.first >> b22.second;

    int ans = -1;

    int cnt = solve(a11, a22, b11, b22);
    if (cnt >= 0) ans = (ans == -1) ? cnt : min(ans, cnt);

    cnt = solve(b11, b22, a11, a22);
    if (cnt >= 0) ans = (ans == -1) ? cnt : min(ans, cnt);

    if (ans < 0) cout << "IMPOSSIBLE" << '\n';
    else cout << ans << '\n';
    return 0;
}
