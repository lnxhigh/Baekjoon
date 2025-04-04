#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using Point = pair<int,int>;
const int MAX = 1 << 7, MAXH = 10001;

int R, C;
int H[MAX][MAX];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

// https://rapun7el.tistory.com/137
queue<Point> queues[MAXH];
int vis[MAX][MAX];

int main() {
    FastIO
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> H[i][j];
        }
    }

    int ans = 0;
    queues[0].push({ 0, 0 });
    vis[0][0]++;

    for (int level = 0; level < MAXH; level++) {
        queue<Point> &q = queues[level];

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            ans += level - H[x][y];

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= R + 2 || ny < 0 || ny >= C + 2) continue;
                else if (vis[nx][ny]++) continue;
                
                if (H[nx][ny] <= level) q.push({ nx, ny });
                else queues[H[nx][ny]].push({ nx, ny });
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
