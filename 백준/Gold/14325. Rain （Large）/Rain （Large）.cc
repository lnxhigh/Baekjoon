#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 50;

int TC;

int R, C;
int H[MAX][MAX];
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

void input() {
    cin >> R >> C;
    memset(H, 0, sizeof(H));
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> H[i][j];
        }
    }
}

bool isEdge(int x, int y) {
    return x == 0 || x == R - 1 || y == 0 || y == C - 1;
}

bool isInside(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

int bfs() {
    // Initialize
    int ret = 0;
    priority_queue<tuple<int,int,int>> pq;
    bool V[MAX][MAX];

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            V[i][j] = isEdge(i, j);
            if (V[i][j]) pq.push({ -H[i][j], i, j });
        }
    }

    while (!pq.empty()) {
        auto [height, cx, cy] = pq.top();
        height = -height;
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (!isInside(nx, ny) || V[nx][ny]) continue;
            
            int diff = max(height - H[nx][ny], 0);
            ret += diff;

            pq.push({ -max(height, H[nx][ny]), nx, ny });
            V[nx][ny] = true;
        }
    }

    return ret;
}

int main() {
    FastIO
    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        input();
        int ans = bfs();
        cout << "Case #" << tc << ": " << ans << "\n";
    }

    return 0;
}
