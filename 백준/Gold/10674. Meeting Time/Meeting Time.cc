#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAXN = 101, MAXT = 101;

int n, m;
vector<tuple<int,int,int>> graph[MAXN];

queue<pair<int,int>> queues[MAXN * MAXT];
bool vis[2][MAXN][MAXN * MAXT];

int main() {
    FastIO

    cin >> n >> m;
    while (m--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        graph[a].push_back({ b, c, d });
    }

    // time -> node + idx
    queues[0].push({ 1, 0 });
    queues[0].push({ 1, 1 });
    vis[0][1][0] = vis[1][1][0] = true;

    for (int t = 0; t < MAXN * MAXT; t++) {
        queue<pair<int,int>> &q = queues[t];

        while (!q.empty()) {
            auto [a, idx] = q.front();
            q.pop();

            for (const auto& [b, c, d] : graph[a]) {
                int add = (idx == 0) ? c : d;

                if (!vis[idx][b][t + add]) {
                    queues[t + add].push({ b, idx });
                    vis[idx][b][t + add] = true;
                }
            }
        }
    }

    int ans = -1;
    for (int t = MAXN * MAXT - 1; t >= 0; t--) {
        if (vis[0][n][t] && vis[1][n][t]) ans = t;
    }

    if (ans < 0) cout << "IMPOSSIBLE" << '\n';
    else cout << ans << '\n';

    return 0;
}
