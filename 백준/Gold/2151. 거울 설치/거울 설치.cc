#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 50;

int N;
char A[MAX][MAX];
bool visited[MAX][MAX][4];

pair<int,int> S;
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

void input() {
    N; cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            if (A[i][j] == '#') S = { i, j };
        }
    }
}

bool inside(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) return false;
    return true;
}

int bfs(int x, int y) {
    deque<pair<tuple<int,int,int>, int>> dq;

    // Initialize
    assert(A[x][y] == '#');
    A[x][y] = '.';

    for (int i = 0; i < 4; i++) {
        auto init = make_tuple(x, y, i);
        dq.push_front({ init, 0 });
        visited[x][y][i] = true;
    }

    // Search
    while (!dq.empty()) {
        auto [t, cost] = dq.front();
        auto [x, y, dir] = t;
        if (A[x][y] == '#') return cost;
        dq.pop_front();

        for (int i : { dir, (dir + 1) % 4, (dir + 3) % 4 }) {
            if (A[x][y] != '!' && i != dir) continue;

            int nx = x + dx[i], ny = y + dy[i];
            if (!inside(nx, ny) || visited[nx][ny][i]) continue;
            if (A[nx][ny] == '*') continue;

            auto next = make_tuple(nx, ny, i);
            if (i == dir) dq.push_front({ next, cost });
            else dq.push_back({ next, cost + 1 });
            visited[nx][ny][i] = true;
        }
    }
    
    return -1;
}

int main() {
    FastIO
    input();

    auto [x, y] = S;
    int ans = bfs(x, y);
    cout << ans << '\n';

    return 0;
}
