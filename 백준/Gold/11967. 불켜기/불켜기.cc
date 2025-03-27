#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 7;

int N, M;
vector<pair<int,int>> switches[MAX][MAX];
bool isLit[MAX][MAX];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

bool BFS() {
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(N, vector<bool>(N));
    bool update = false;

    q.push({ 0, 0 });
    visited[0][0] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [a, b] : switches[x][y]) {
            if (!isLit[a][b]) {
                update = true;
                isLit[a][b] = true;
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            else if (!isLit[nx][ny] || visited[nx][ny]) continue;

            q.push({ nx, ny });
            visited[nx][ny] = true;
        }
    }

    return update;
}

int main() {
    FastIO
    cin >> N >> M;

    while (M--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        --x, --y, --a, --b;
        switches[x][y].push_back({ a, b });
    }

    isLit[0][0] = true;
    while (BFS());
    
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (isLit[i][j]) cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}
