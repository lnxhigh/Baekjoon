#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 51;

int n;
string arr[MAX];

int t[128];
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

bool dist[MAX][MAX][2];
bool vis[MAX][MAX][2];

bool out_of_bounds(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n;
}

vector<pair<int,int>> generate(int x, int y, int z) {
    vector<pair<int,int>> vec;
    if (z == 0) vec = {{x, y}, {x + dx[1], y + dy[1]}, {x + dx[3], y + dy[3]}};
    else vec = {{x, y}, {x + dx[0], y + dy[0]}, {x + dx[2], y + dy[2]}};
    return vec;
}

tuple<int,int,int> find(char c) {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (arr[x][y] != c) continue;

            vector<pair<int,int>> vec[2] = { generate(x, y, 0), generate(x, y, 1) };

            for (int z = 0; z <= 1; z++) {
                bool chk = true;
                for (auto [nx, ny] : vec[z]) {
                    if (out_of_bounds(nx, ny) || arr[nx][ny] != c) {
                        chk = false;
                    }
                }

                if (chk) {
                    return { x, y, z };
                }
            }
        }
    }

    return { -1, -1, -1 };
}

bool try_move(int x, int y, int z, char code) {
    if (code == 'T') {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nx = x + i, ny = y + j;
                if (out_of_bounds(nx, ny) || arr[nx][ny] == '1') {
                    return false;
                }
            }
        }
    }
    else {
        vector<pair<int,int>> p = generate(x, y, z);

        int dir = t[code];
        for (auto [x, y] : p) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (out_of_bounds(nx, ny) || arr[nx][ny] == '1') {
                return false;
            }
        }
    }

    return true;
}

int main() {
    FastIO

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    string behavior = "UDLRT";
    t['U'] = 0, t['D'] = 2, t['L'] = 1, t['R'] = 3;

    auto [sx, sy, sz] = find('B');
    auto [ex, ey, ez] = find('E');

    queue<tuple<int,int,int,int>> q;
    q.push({ sx, sy, sz, 0 });
    vis[sx][sy][sz] = true;

    int ans = 0;

    while (!q.empty() && ans == 0) {
        auto [x, y, z, cnt] = q.front();
        q.pop();

        if (x == ex && y == ey && z == ez) {
            ans = cnt;
            break;
        }
        
        for (char code : behavior) {
            if (!try_move(x, y, z, code)) continue;

            int nx = x, ny = y, nz = z;
            int dir = t[code];

            if (code == 'T') nz = 1 - nz;
            else nx += dx[dir], ny += dy[dir];

            if (!vis[nx][ny][nz]) {
                q.push({ nx, ny, nz, cnt + 1 });
                vis[nx][ny][nz] = true;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
