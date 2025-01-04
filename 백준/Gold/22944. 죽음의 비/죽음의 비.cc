#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 9;
const int INF = 1 << 20;

int N, H, D;
char A[MAX][MAX];
pair<int,int> S, E;

int V[MAX][MAX];
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

void input() {
    cin >> N >> H >> D;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c; cin >> c;
            A[i][j] = c;

            if (c == 'S') S = { i, j };
            else if (c == 'E') E = { i, j };
        }
    }
}

int solve() {
    int ret = INF;
    auto [x, y] = S;
    memset(V, -1, sizeof(V));

    queue<tuple<int,int,int,int,int>> q;
    q.push({ x, y, H, 0, 0 });
    V[x][y] = H;
    
    while (!q.empty()) {
        auto [x, y, h, d, cnt] = q.front();
        q.pop();

        if (A[x][y] == 'E') ret = min(ret, cnt);
        if (h == 0) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            int nh = h, nd = (A[nx][ny] != 'U') ? d : D;
            nd ? nd-- : nh--;
            if (V[nx][ny] >= nh + nd) continue;

            q.push({ nx, ny, nh, nd, cnt + 1 });
            V[nx][ny] = nh + nd;
        }
    }

    return ret < INF ? ret : -1;
}

int main() {
    FastIO
    input();
    cout << solve() << '\n';
    return 0;
}
