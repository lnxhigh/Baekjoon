#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 6;

int R, C;
vector<string> Map;

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };
bool visited[MAX][MAX][MAX];

int bfs(int x, int y) {
    // x y keys moves
    queue<tuple<int,int,int,int>> q;
    q.push({ x, y, 0, 0 });
    visited[x][y][0] = true;

    // search
    while (!q.empty()) {
        auto [x, y, keys, moves] = q.front();
        q.pop();
        if (Map[x][y] == '1') return moves;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

            if (Map[nx][ny] == '.' || Map[nx][ny] == '0' || Map[nx][ny] == '1') {
                if (!visited[nx][ny][keys]) {
                    q.push({ nx, ny, keys, moves + 1 });
                    visited[nx][ny][keys] = true;
                }
            }
            else if (Map[nx][ny] >= 'a' && Map[nx][ny] <= 'z') {
                int keyIdx = (int)(Map[nx][ny] - 'a');
                int newKeys = keys | (1 << keyIdx);
                if (!visited[nx][ny][newKeys]) {
                    q.push({ nx, ny, newKeys, moves + 1 });
                    visited[nx][ny][newKeys] = true;
                }
            }
            else if (Map[nx][ny] >= 'A' && Map[nx][ny] <= 'Z') {
                int keyIdx = (int)(Map[nx][ny] - 'A');
                if (keys >> keyIdx & 1) {
                    if (!visited[nx][ny][keys]) {
                        q.push({ nx, ny, keys, moves + 1 });
                        visited[nx][ny][keys] = true;
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
    FastIO
    cin >> R >> C;
    Map.resize(R);
    for (string &line : Map) cin >> line;

    int x = 0, y = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (Map[i][j] == '0') {
                x = i, y = j;
            }
        }
    }
    
    int ans = bfs(x, y);
    cout << ans << '\n';
    return 0;
}
