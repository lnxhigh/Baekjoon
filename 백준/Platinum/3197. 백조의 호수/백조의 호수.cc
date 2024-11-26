#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using Point = pair<int,int>;

int R, C;
char Lake[1500][1500];
bool visited[1500][1500];
bool visited_swan[1500][1500];

int L = 0;
int sx, sy;
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

void input() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> Lake[i][j];
            if (Lake[i][j] == 'L') {
                L++;
                sx = i, sy = j;
            }
        }
    }
}

bool inside(int x, int y) {
    if (x < 0 || x >= R || y < 0 || y >= C) return false;
    return true;
}

bool canMelt(int x, int y) {
    if (Lake[x][y] != 'X') return false;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (inside(nx, ny) && Lake[nx][ny] != 'X') {
            return true;
        }
    }
    
    return false;
}

void update(int x, int y) {
    // Return early if (x, y) is not connected to the first swan
    bool check = (x == sx && y == sy);
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!inside(nx, ny)) continue;
        if (Lake[nx][ny] == 'X' || !visited_swan[nx][ny]) continue;
        
        check = true;
        break;
    }
    if (!check) return;

    // Move swan to (x, y)
    queue<Point> q;

    Point init = { x, y };
    q.push(init);
    visited_swan[x][y] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        if (Lake[x][y] == 'L') L--;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!inside(nx, ny)) continue;
            if (visited_swan[nx][ny] || Lake[nx][ny] == 'X') continue;
            
            Point next = { nx, ny };
            q.push(next);
            visited_swan[nx][ny] = true;
        }
    }
}

int bfs() {
    queue<pair<Point, int>> q;

    // Initialize
    for (int x = 0; x < R; x++) {
        for (int y = 0; y < C; y++) {
            if (!canMelt(x, y)) continue;
            
            Point p = { x, y };
            pair<Point, int> init = { p, 1 };
            q.push(init);
            visited[x][y] = true;
        }
    }

    // Search
    while (!q.empty()) {
        auto [p, day] = q.front();
        auto [x, y] = p;
        q.pop();

        // Move swan to find another swan
        Lake[x][y] = '.';
        update(x, y);

        // Return when all swans are found
        if (L == 0) return day;
        
        // Find glaciers that will melt the next day.
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!inside(nx, ny)) continue;
            if (visited[nx][ny] || Lake[nx][ny] != 'X') continue;
            
            Point next = { nx, ny };
            q.push({ next, day + 1 });
            visited[nx][ny] = true;
        }
    }

    return -1;
}

int solve() {
    update(sx, sy);
    if (L == 0) return 0;
    int ret = bfs();
    return ret;
}

int main() {
    FastIO
    input();
    int ans = solve();
    cout << ans << '\n';
    return 0;
}
