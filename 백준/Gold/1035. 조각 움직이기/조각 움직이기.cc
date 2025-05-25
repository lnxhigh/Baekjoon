#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

const int n = 5;
string arr[5];

int k;
vector<pair<int,int>> stars;

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

int t = 0;
int vis[5][5];

int bits = 0;
int ans = 1 << 20;

int dfs(int x, int y, int t) {
    int cnt = 0;
    vis[x][y] = t;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        else if (((bits >> (nx * n + ny) & 1) == 0) || (vis[nx][ny] == t)) continue;
        cnt += dfs(nx, ny, t);
    }

    return ++cnt;
}

int main() {
    FastIO

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == '*') stars.emplace_back(i, j);
        }
    }

    k = stars.size();
    sort(stars.begin(), stars.end());

    vector<int> all;

    for (bits = 0; bits < (1 << 25); bits++) {
        int cnt = __builtin_popcount(bits);
        if (cnt != k) continue;

        int idx = 0;
        while ((bits >> idx & 1) == 0) idx++;
        if (dfs(idx / n, idx % n, ++t) == k) all.emplace_back(bits);
    }

    do {
        for (int bits : all) {
            int sum = 0, cnt = 0;

            for (int i = 0; i < 25; i++) {
                if ((bits >> i & 1) == 0) continue;
                int x = i / n, y = i % n;

                auto [sx, sy] = stars[cnt++];
                sum += abs(x - sx) + abs(y - sy);
            }

            ans = min(ans, sum);
        }

    } while (next_permutation(stars.begin(), stars.end()));

    cout << ans << '\n';

    return 0;
}
