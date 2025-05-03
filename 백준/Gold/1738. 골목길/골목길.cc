#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 101;
const int INF = 100'000'000;

int n, m;
bool adj[MAX][MAX];
vector<pair<int,int>> graph[MAX];

int dist[MAX];
int pre[MAX];

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                adj[i][j] |= (adj[i][k] && adj[k][j]);
            }
        }
    }
}

bool bellman_ford(int x) {
    fill(dist, dist + MAX, INF);
    dist[x] = 0;

    bool has_cycle = false;
    
    for (int k = 1; k <= n; k++) {
        for (int cur = 1; cur <= n; cur++) {
            if (!adj[cur][n]) continue;
            if (dist[cur] == INF) continue;
            
            for (auto [nxt, w] : graph[cur]) {
                if (dist[nxt] > dist[cur] + w) {
                    dist[nxt] = dist[cur] + w;
                    pre[nxt] = cur;
                    has_cycle |= (k == n);
                }
            }
        }
    }

    return !has_cycle && dist[n] < INF;
}

int main() {
    FastIO

    cin >> n >> m;
    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        adj[u][v] = true;
        graph[u].emplace_back(v, -w);
    }

    floyd();
    bool chk = bellman_ford(1);

    if (chk) {
        stack<int> path;
        for (int i = n; i > 0; i = pre[i]) path.push(i);
        while (!path.empty()) cout << path.top() << ' ', path.pop();
        cout << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}
