#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 10001;

int n, m;
vector<pair<int,int>> graph[2][MAX];
int src, dst;

int deg[2][MAX];
int dist[2][MAX];

int main() {
    FastIO

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        graph[0][x].emplace_back(y, w);
        graph[1][y].emplace_back(x, w);
        deg[0][y]++, deg[1][x]++;
    }
    cin >> src >> dst;

    queue<pair<int,bool>> q;
    q.push({ src, false });
    q.push({ dst, true });

    while (!q.empty()) {
        auto [x, f] = q.front();
        q.pop();

        for (auto [nxt, w] : graph[f][x]) {
            dist[f][nxt] = max(dist[f][nxt], dist[f][x] + w);
            if (--deg[f][nxt] == 0) q.push({ nxt, f });
        }
    }
    
    int t = dist[0][dst];
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        for (auto [nxt, w] : graph[0][i]) {
            if (t == dist[0][i] + w + dist[1][nxt]) cnt++;
        }
    }

    cout << t << '\n';
    cout << cnt << '\n';

    return 0;
}
