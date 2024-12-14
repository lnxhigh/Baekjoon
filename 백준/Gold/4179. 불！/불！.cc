#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using Point = pair<int,int>;
const int MAX = 1 << 10, INF = 1 << 25;

int R, C;
char Maze[MAX][MAX];
int Jihun[MAX][MAX];
int Fire[MAX][MAX];
bool Visited[MAX][MAX];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

void input() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> Maze[i][j];
        }
    }
}

vector<Point> find(char x) {
    vector<Point> ret;
    ret.reserve(R * C);
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (Maze[i][j] == x) {
                ret.push_back({ i, j });
            }
        }
    }

    return ret;
}

void BFS(const vector<Point> &init, int D[MAX][MAX]) {
    queue<pair<Point,int>> q;
    memset(Visited, 0, sizeof(Visited));

    for (const auto &p : init) {
        auto [x, y] = p;
        q.push({ p, 0 });
        Visited[x][y] = true;
    }

    while (!q.empty()) {
        auto [p, depth] = q.front();
        auto [x, y] = p;
        q.pop();

        D[x][y] = depth;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (Maze[nx][ny] == '#' || Visited[nx][ny]) continue;

            pair<int,int> nxt = { nx, ny };
            q.push({ nxt, depth + 1 });
            Visited[nx][ny] = true;
        }
    }
}

int solve() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            Jihun[i][j] = Fire[i][j] = INF;
        }
    }

    auto start = find('J');
    BFS(start, Jihun);

    auto fires = find('F');
    BFS(fires, Fire);

    int ans = INF;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (i == 0 || i == R - 1 || j == 0 || j == C - 1) {
                if (Jihun[i][j] < Fire[i][j]) {
                    ans = min(ans, Jihun[i][j]);
                }
            }
        }
    }

    if (ans >= INF) return -1;
    return ++ans;
    
}

int main() {
    FastIO
    input();
    int ans = solve();
    if (ans == -1) cout << "IMPOSSIBLE" << '\n';
    else cout << ans << '\n';
    
    return 0;
}
