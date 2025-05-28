#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int r, c, k;
int arr[32][32];
int vis[32][32];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

int dfs(int x, int y, int t) {
    int cnt = 0;
    vis[x][y] = t;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        else if (arr[nx][ny] != arr[x][y] || vis[nx][ny] == t) continue;
        cnt += dfs(nx, ny, t);
    }

    return ++cnt;
}

struct Die {
    int x = 0, y = 0;
    int dir = 3;

    int top = 1, bottom = 6;
    int left = 4, right = 3;
    int front = 5, back = 2;

    void go() {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c) dir = (dir + 2) % 4;
        x += dx[dir], y += dy[dir];

        int* tmp[4] = { &bottom, 0, &top, 0 };

        if (dir == 0) tmp[1] = &back, tmp[3] = &front;
        else if (dir == 1) tmp[1] = &left, tmp[3] = &right;
        else if (dir == 2) tmp[1] = &front, tmp[3] = &back;
        else if (dir == 3) tmp[1] = &right, tmp[3] = &left;
        
        int t = *tmp[0];
        for (int i = 0; i < 4; i++) {
            if (i < 3) *tmp[i] = *tmp[i + 1];
            else *tmp[i] = t;
        }
    }

    void update() {
        int a = bottom;
        int b = arr[x][y];

        if (a > b) dir = (dir + 3) % 4;
        else if (a < b) dir = (dir + 1) % 4;
    }
};

int main() {
    FastIO

    cin >> r >> c >> k;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    Die die;
    int ans = 0;

    for (int i = 1; i <= k; i++) {
        die.go();
        die.update();

        int x = die.x, y = die.y;
        int score = arr[x][y] * dfs(x, y, i);
        ans += score;
    }

    cout << ans << '\n';
    return 0;
}
