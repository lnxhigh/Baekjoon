#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 9;

int r, c;
int arr[MAX][MAX];
bool vis[MAX][MAX];

int ans = 0;
int sum = 0;

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

void dfs(int x, int y, int depth) {
    sum += arr[x][y];
    vis[x][y] = true;

    if (depth == 6) {
        ans = max(ans, sum);
    }
    else {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!arr[nx][ny] || vis[nx][ny]) continue;

            dfs(nx, ny, depth + 1);

            int lx = x + dx[(i + 1) & 0b11], ly = y + dy[(i + 1) & 0b11];
            int rx = x + dx[(i + 3) & 0b11], ry = y + dy[(i + 3) & 0b11];

            if (depth == 3) {
                if (arr[lx][ly] && arr[rx][ry] && !vis[lx][ly] && !vis[rx][ry]) {
                    ans = max(ans, sum + arr[nx][ny] + arr[lx][ly] + arr[rx][ry]);
                }
            }

            if (depth == 2 || depth == 3 || depth == 4) {

                if (arr[lx][ly] && !vis[lx][ly]) {
                    sum += arr[lx][ly];
                    vis[lx][ly] = true;

                    dfs(nx, ny, depth + 2);

                    sum -= arr[lx][ly];
                    vis[lx][ly] = false;
                }

                if (arr[rx][ry] && !vis[rx][ry]) {
                    sum += arr[rx][ry];
                    vis[rx][ry] = true;

                    dfs(nx, ny, depth + 2);

                    sum -= arr[rx][ry];
                    vis[rx][ry] = false;
                }
            }
        }
    }
    
    sum -= arr[x][y];
    vis[x][y] = false;
}

int main() {
    FastIO
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            dfs(i, j, 1);
        }
    }

    cout << ans << '\n';
    return 0;
}
