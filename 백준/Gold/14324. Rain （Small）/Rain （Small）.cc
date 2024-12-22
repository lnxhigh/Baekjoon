#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using Point = pair<int,int>;
const int MAX = 50;

int TC;

int R, C;
int H[MAX][MAX];

int T[MAX][MAX];
bool V[MAX][MAX];
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

bool bfs(int x, int y, int level) {
    // Initialize
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            T[i][j] = max(H[i][j], level);
        }
    }
    memset(V, false, sizeof(V));

    // BFS
    queue<Point> q;
    q.push({ x, y });
    V[x][y] = true;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        if (cx == 0 || cx == R - 1 || cy == 0 || cy == C - 1) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (T[nx][ny] > T[x][y] || V[nx][ny]) continue;

            q.push({ nx, ny });
            V[nx][ny] = true;
        }
    }

    return false;
}

int search(int x, int y) {
    int level = H[x][y];
    int low = H[x][y], high = 1000;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (bfs(x, y, mid)) {
            level = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    int diff = level - H[x][y];
    return diff;
}

int solve() {
    int ret = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            ret += search(i, j);
        }
    }
    return ret;
}

int main() {
    FastIO
    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        input();
        int ans = solve();
        cout << "Case #" << tc << ": " << ans << "\n";
    }

    return 0;
}
