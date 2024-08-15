#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX = 1 << 7;
const int INF = 1 << 14;

bool land[MAX][MAX];
bool visited[MAX][MAX];
int group[MAX][MAX];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

void dfs(int x, int y, int k) {
    visited[x][y] = true;
    group[x][y] = k; // divide lands
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (visited[nx][ny] || !land[nx][ny]) continue;
        
        dfs(nx, ny, k);
    }
}

int bfs(int sx, int sy) {
    deque<pair<pair<int,int>,int>> dq;

    dq.push_front({ {sx,sy}, 0 });
    fill(&visited[0][0], &visited[N-1][N-1] + 1, false);
    visited[sx][sy] = true;

    while (!dq.empty()) {
        pair<int,int> loc = dq.front().first;
        int x = loc.first, y = loc.second;
        int depth = dq.front().second;

        dq.pop_front();

        // return when reaching another land
        if (land[x][y] && group[x][y] != group[sx][sy]) return depth;

        // explore
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;
            pair<int,int> next = { nx, ny };
            if (land[nx][ny]) dq.push_front({ next, depth }); // no cost
            else dq.push_back({ next, depth+1 }); // take cost to build a bridge
        }
    }

    return INF;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> land[i][j];
        }
    }

    int K = 0;
    vector<pair<int,int>> starts;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] || !land[i][j]) continue;
            starts.push_back({ i, j });
            dfs(i, j, ++K);
        }
    }

    int res = INF;
    for (auto p : starts) {
        int sx = p.first, sy = p.second;
        int cnt = bfs(sx, sy);
        res = min(res, cnt);
    }

    cout << res << '\n';
    return 0;
}
