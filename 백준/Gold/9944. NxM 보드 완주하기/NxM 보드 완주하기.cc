#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 5;
const int INF = 1 << 30;

int R, C;
char arr[MAX][MAX];
bool vis[MAX][MAX];
int res[MAX * MAX];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

bool check(int x, int y) {
    if (x < 0 || x >= R || y < 0 || y >= C) return false;
    else if (arr[x][y] == '*' || vis[x][y]) return false;
    return true;
}

void dfs(int x, int y, int dir, int cnt, int val) {
    cnt++;
    vis[x][y] = true;
    res[cnt] = min(res[cnt], val);

    int nx = x + dx[dir], ny = y + dy[dir];

    if (check(nx, ny)) {
        dfs(nx, ny, dir, cnt, val);
    }
    else {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            
            if (check(nx, ny)) {
                dfs(nx, ny, i, cnt, val + 1);
            }
        }
    }
    
    cnt--;
    vis[x][y] = false;
}

int main() {
    FastIO
    int t = 0;
    while (++t) {
        cin >> R >> C;
        if (cin.eof()) break;

        memset(arr, 0, sizeof(arr));
        memset(vis, false, sizeof(vis));
        fill(res, res + MAX * MAX, INF);

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> arr[i][j];
            }
        }

        // Solve
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (arr[i][j] == '*') continue;

                for (int dir = 0; dir < 4; dir++) {
                    dfs(i, j, dir, 0, 1);
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (arr[i][j] == '.') cnt++;
            }
        }

        int ans = (res[cnt] < INF) ? res[cnt] : -1;
        if (cnt <= 1) ans = 0;

        cout << "Case " << t << ": ";
        cout << ans << '\n';
    }

    return 0;
}
