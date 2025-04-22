#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAXR = 10001, MAXC = 501;
int r, c;
vector<string> arr;

int path[MAXC];
bool vis[MAXR][MAXC];

bool dfs(int x, int y) {
    vis[x][y] = true;
    if (y == c - 1) return true;

    for (int nxt : { x - 1, x, x + 1 }) {
        if (nxt < 0 || nxt >= r) continue;
        else if (arr[nxt][y + 1] == 'x' || vis[nxt][y + 1]) continue;

        path[y] = nxt - x;
        bool chk = dfs(nxt, y + 1);
        if (!chk) continue;

        if (y == 0) {
            int cur = x;
            for (int i = 0; i < c; i++) {
                vis[cur][i] = true;
                cur += path[i];
            }
        }

        return true;
    }

    return false;
}

int main() {
    FastIO
    cin >> r >> c;
    arr.resize(r);
    for (string &line : arr) cin >> line;

    int ans = 0;

    for (int i = 0; i < r; i++) {
        if (arr[i][0] == 'x') continue;

        bool chk = dfs(i, 0);
        if (chk) ans++;
    }

    cout << ans << '\n';
    return 0;
}
