#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int N;
int A[MAX][MAX];
bool D[MAX][MAX];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

bool bfs(int diff) {
    memset(D, false, sizeof(D));
    
    queue<pair<int,int>> q;
    q.push({ 0, 0 });
    D[0][0] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == N - 1 && y == N - 1) return true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (abs(A[x][y] - A[nx][ny]) > diff || D[nx][ny]) continue;

            q.push({ nx, ny });
            D[nx][ny] = true;
        }
    }

    return false;
}

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    int ans = 1 << 30;
    int low = 0, high = 1 << 30;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (bfs(mid)) ans = mid, high = mid - 1;
        else low = mid + 1;
    }

    cout << ans << '\n';
    return 0;
}
