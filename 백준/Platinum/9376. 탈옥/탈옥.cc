#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 111;

int H, W;
char Map[MAX][MAX];
int A[MAX][MAX], B[MAX][MAX], E[MAX][MAX];

struct Info {
    pair<int,int> loc;
    int cost;
    Info(pair<int,int> __loc, int __cost) {
        loc = __loc, cost = __cost;
    }
};

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

void input() {
    // Initialization
    memset(Map, 0, sizeof(Map));
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    memset(E, -1, sizeof(E));

    // Input
    cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> Map[i][j];
        }
    }

    // Pad for simple implementation
    H += 2, W += 2;

    for (int i = 0; i < H; i++) {
        Map[i][0] = Map[i][W - 1] = '.';
    }
    for (int i = 0; i < W; i++) {
        Map[0][i] = Map[H - 1][i] = '.';
    }
}

void bfs(int x, int y, int D[MAX][MAX]) {
    deque<Info> dq;
    bool V[MAX][MAX];
    memset(V, 0, sizeof(V));

    // Initialize
    Info init({ x, y }, 0);
    dq.push_front(init);
    V[x][y] = true;

    // Search
    while (!dq.empty()) {
        auto front = dq.front();
        auto [x, y] = front.loc;
        int cost = front.cost;
        dq.pop_front();

        D[x][y] = cost;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (Map[nx][ny] == '*' || V[nx][ny]) continue;

            pair<int,int> nxt = { nx, ny };
            if (Map[nx][ny] != '#') dq.push_front(Info(nxt, cost));
            else dq.push_back(Info(nxt, cost + 1));
            V[nx][ny] = true;
        }
    }
}

int solve() {
    // Find two prisoners
    int cnt = 0;
    pair<int,int> p[2];

    for (int i = 0; i < H; i++) 
        for (int j = 0; j < W; j++) 
            if (Map[i][j] == '$') 
                p[cnt++] = { i, j };

    // Shortest distance from (x, y)
    bfs(0, 0, E);
    
    auto [Ax, Ay] = p[0];
    bfs(Ax, Ay, A);

    auto [Bx, By] = p[1];
    bfs(Bx, By, B);

    // Minimize the number of doors to open
    int ans = A[0][0] + B[0][0];

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (Map[i][j] != '#') continue;
            if (A[i][j] == -1 || B[i][j] == -1 || E[i][j] == -1) continue;

            // Meet in the middle
            int each = A[i][j] + B[i][j] - 1;

            // Escape from the door
            int share = E[i][j] - 1;
            ans = min(ans, each + share);
        }
    }

    cout << ans << '\n';
    return ans;
}

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        input();
        solve();
    }
    return 0;
}
