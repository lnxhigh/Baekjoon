#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int R, C;
int A[5][5];

bool D[5][5];
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

bool check(int x, int y, int dir) {
    int mx = x + dx[dir], my = y + dy[dir];
    if (mx < 0 || mx >= R || my < 0 || my >= C) return false;

    int nx = x + dx[(dir + 1) % 4], ny = y + dy[(dir + 1) % 4];
    if (nx < 0 || nx >= R || ny < 0 || ny >= C) return false;

    if (D[x][y] || D[mx][my] || D[nx][ny]) return false;
    return true;
}

void solve(int x, int y, int sum, int& ans) {
    if (x == R) {
        ans = max(ans, sum);
        return;
    }
    else if (y == C) {
        solve(x + 1, 0, sum, ans);
        return;
    }

    solve(x, y + 1, sum, ans);

    for (int dir = 0; dir < 4; dir++) {
        if (!check(x, y, dir)) continue;

        int mx = x + dx[dir], my = y + dy[dir];
        int nx = x + dx[(dir + 1) % 4], ny = y + dy[(dir + 1) % 4];
        int add = (A[x][y] << 1) + A[mx][my] + A[nx][ny];
        
        D[x][y] = D[mx][my] = D[nx][ny] = true;
        solve(x, y + 1, sum + add, ans);
        D[x][y] = D[mx][my] = D[nx][ny] = false;
    }
}

int main() {
    FastIO
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> A[i][j];
        }
    }

    int ans = 0;
    solve(0, 0, 0, ans);
    cout << ans << '\n';

    return 0;
}
