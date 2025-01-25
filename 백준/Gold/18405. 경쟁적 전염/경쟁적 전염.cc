#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 205;

int N, K;
int S, X, Y;
int A[MAX][MAX];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

void input() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    cin >> S >> X >> Y;
    --X, --Y;
}

int bfs() {
    vector<tuple<int,int,int>> virus;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j]) virus.push_back({ A[i][j], i, j });
        }
    }
    sort(virus.begin(), virus.end());

    queue<tuple<int,int,int>> q;
    for (auto [_, x, y] : virus) {
        q.push({ x, y, 0 });
    }

    while (!q.empty()) {
        auto [x, y, t] = q.front();
        q.pop();
        if (x == X && y == Y) return t <= S ? A[x][y] : 0;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            else if (A[nx][ny]) continue;

            q.push({ nx, ny, t + 1 });
            A[nx][ny] = A[x][y];
        }
    }

    return 0;
}

int main() {
    FastIO
    input();
    int ans = bfs();
    cout << ans << '\n';
    return 0;
}
