#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int s, n, k, r1, r2, c1, c2;

bool dfs(int x, int y, int t) {
    if (t == 0) return false;

    int nx = x / n, ny = y / n;
    int m = (n - k) / 2;
    if (dfs(nx, ny, t - 1)) return true;
    return x >= nx * n + m && x < (nx + 1) * n - m && y >= ny * n + m && y < (ny + 1) * n - m;
}

int main() {
    FastIO
    cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;

    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            cout << dfs(i, j, s);
        }
        cout << '\n';
    }

    return 0;
}
