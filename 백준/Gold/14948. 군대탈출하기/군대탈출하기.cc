#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 7;

int R, C;
int A[MAX][MAX];
bool S[MAX][MAX], T[MAX][MAX];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

void input() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> A[i][j];
        }
    }
}

void bfs(int x, int y, int k, bool D[MAX][MAX]) {
    if (A[x][y] > k) return;
    
    bool V[MAX][MAX];
    memset(V, 0, sizeof(V));

    queue<pair<int,int>> q;
    
    pair<int,int> init = { x, y };
    q.push(init);
    V[x][y] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        D[x][y] = true;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (A[nx][ny] > k || V[nx][ny]) continue;

            pair<int,int> nxt = { nx, ny };
            q.push(nxt);
            V[nx][ny] = true;
        }
    }
}

bool f(int k) {
    // Source
    memset(S, 0, sizeof(S));
    bfs(0, 0, k, S);

    // Destination
    memset(T, 0, sizeof(T));
    bfs(R - 1, C - 1, k, T);

    // Direct arrival
    if (S[R - 1][C - 1] || T[0][0]) return true;

    // Use special equipment
    for (int x = 0; x < R; x++) {
        for (int y = 0; y < C; y++) {
            if (!S[x][y]) continue;
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i] * 2, ny = y + dy[i] * 2;
                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (T[nx][ny]) return true;
            }
        }
    }

    return false;
}

int solve() {
    int ans = 1 << 30;
    int low = 0, high = 1 << 30;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (f(mid)) ans = mid, high = mid - 1;
        else low = mid + 1;
    }

    return ans;
}

int main() {
    FastIO
    input();
    int ans = solve();
    cout << ans << '\n';
    return 0;
}
