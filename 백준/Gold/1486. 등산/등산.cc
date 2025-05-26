#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 25 * 25;
const int INF = 1 << 29;

int r, c, t, d;
vector<string> arr;
int dist[MAX][MAX];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

int f(char x) {
    if (x >= 'A' && x <= 'Z') return (int)(x - 'A');
    return (int)(x - 'a') + 26;
}

int main() {
    FastIO

    // Input

    cin >> r >> c >> t >> d;
    arr.resize(r);
    for (string& line : arr) cin >> line;

    // Build graph

    int n = r * c;
    for (int i = 0; i < n; i++) {
        fill(dist[i], dist[i] + n, INF);
        dist[i][i] = 0;
    }

    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            int cur = f(arr[x][y]);

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;

                int nxt = f(arr[nx][ny]);
                int delta = nxt - cur;
                if (abs(delta) > t) continue;

                dist[x*c + y][nx*c + ny] = (delta > 0) ? delta * delta : 1;
            }
        }
    }

    // Floyd

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Result

    int ans = f(arr[0][0]);
    for (int i = 0; i < n; i++) {
        bool chk = (dist[0][i] + dist[i][0] <= d);
        if (chk) ans = max(ans, f(arr[i / c][i % c]));
    }

    cout << ans << '\n';
    return 0;
}
