#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

char arr[20][20];
int dist[20][20][20][20];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

int main() {
    FastIO

    while (true) {
        int c, r; cin >> c >> r;
        if (r == 0 && c == 0) break;
        
        memset(arr, 0, sizeof(arr));
        memset(dist, -1, sizeof(dist));
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> arr[i][j];
            }
        }

        for (int x = 0; x < r; x++) {
            for (int y = 0; y < c; y++) {
                if (arr[x][y] == 'x') continue;

                queue<tuple<int,int,int>> q;
                bool vis[20][20] = { false };

                q.push({ x, y, 0 });
                vis[x][y] = true;

                while (!q.empty()) {
                    auto [cx, cy, cnt] = q.front();
                    q.pop();
                    
                    dist[x][y][cx][cy] = cnt;

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cx + dx[dir], ny = cy + dy[dir];
                        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                        else if (arr[nx][ny] == 'x' || vis[nx][ny]) continue;

                        q.push({ nx, ny, cnt + 1 });
                        vis[nx][ny] = true;
                    }
                }
            }
        }

        int mx = -1, my = -1;
        vector<pair<int,int>> dirty;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (arr[i][j] == 'o') mx = i, my = j;
                else if (arr[i][j] == '*') dirty.push_back({ i, j });
            }
        }

        sort(dirty.begin(), dirty.end());

        int ans = -1;

        do {
            int sum = 0;
            int x = mx, y = my;

            for (size_t i = 0; i < dirty.size() && sum != -1; i++) {
                const auto& [nx, ny] = dirty[i];
                if (dist[x][y][nx][ny] < 0) sum = -1;
                else sum += dist[x][y][nx][ny], x = nx, y = ny;
            }

            if (sum != -1) ans = (ans < 0) ? sum : min(ans, sum);

        } while (next_permutation(dirty.begin(), dirty.end()));

        cout << ans << '\n';
    }

    return 0;
}
