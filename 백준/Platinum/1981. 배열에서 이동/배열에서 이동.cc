#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 7;

int N;
int A[MAX][MAX];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
}

bool bfs(int mn, int mx) {
    if ((A[0][0] < mn || A[0][0] > mx)) return false;
    if ((A[N - 1][N - 1] < mn || A[N - 1][N - 1] > mx)) return false;

    queue<pair<int,int>> q;
    vector<vector<bool>> V(N, vector<bool>(N));
    
    q.push({ 0, 0 });
    V[0][0] = true;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (x == N - 1 && y == N - 1) return true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if ((A[nx][ny] < mn || A[nx][ny] > mx) || V[nx][ny]) continue;

            q.push({ nx, ny });
            V[nx][ny] = true;
        }
    }

    return false;
}

bool check(int len) {
    for (int i = 0; i + len <= 200; i++) {
        if (bfs(i, i + len)) {
            return true;
        }
    }
    return false;
}

int solve() {
    int ret = -1;
    int low = 0, high = 200;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(mid)) ret = mid, high = mid - 1;
        else low = mid + 1;
    }
    return ret;
}

int main() {
    FastIO
    input();
    int ans = solve();
    cout << ans << '\n';
    return 0;
}
