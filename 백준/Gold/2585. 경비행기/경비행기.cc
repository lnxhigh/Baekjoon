#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;
const long long INF = 1LL << 60;

int n, k;
pair<int,int> dat[MAX];

double dist[MAX][MAX];
pair<int,int> src = { 0, 0 };
pair<int,int> dst = { 10000, 10000 };

int bfs(double fuel) {
    queue<pair<int,int>> q;
    q.push({ 0, 0 });
    vector<bool> vis(n + 1);
    vis[0] = true;

    while (!q.empty()) {
        auto [from, cnt] = q.front();
        q.pop();

        for (int to = 0; to <= n + 1; to++) {
            if (dist[from][to] <= fuel && !vis[to]) {
                q.push({ to, cnt + 1 });
                vis[to] = true;

                if (to == n + 1) return cnt;
            }
        }
    }

    return -1;
}

int main() {
    FastIO
    cin >> n >> k;

    // data

    dat[0] = src;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        dat[i] = { x, y };
    }
    dat[n + 1] = dst;

    // cache

    for (int i = 0; i <= n + 1; i++) {
        for (int j = i; j <= n + 1; j++) {
            int dx = dat[i].first - dat[j].first;
            int dy = dat[i].second - dat[j].second;
            double r = sqrt(dx * dx + dy * dy);

            dist[i][j] = dist[j][i] = r;
        }
    }

    int ans = 0;
    int lo = 0, hi = 1 << 11;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        double fuel = mid * 10;

        int cnt = bfs(fuel);
        bool chk = (cnt != -1) && (cnt <= k);
        
        if (chk) ans = mid, hi = mid - 1;
        else lo = mid + 1;
    }

    cout << ans << '\n';
    return 0;
}
