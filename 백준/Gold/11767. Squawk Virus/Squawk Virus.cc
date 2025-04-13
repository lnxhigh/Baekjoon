#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const int MAX = 1 << 7;

int n, m, s, t;
ll cur[MAX];
ll nxt[MAX];
ll mat[MAX][MAX];

int main() {
    FastIO
    cin >> n >> m >> s >> t;
    
    while (m--) {
        int x, y; cin >> x >> y;
        mat[x][y] = mat[y][x] = 1;
    }

    cur[s] = 1;
    
    while (t--) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                nxt[i] += mat[i][j] * cur[j];
            }
        }

        for (int i = 0; i < n; i++) {
            cur[i] = nxt[i];
            nxt[i] = 0;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += cur[i];
    }

    cout << ans << '\n';
    return 0;
}
