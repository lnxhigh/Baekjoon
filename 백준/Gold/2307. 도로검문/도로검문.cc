#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;
const int INF = 1 << 28;

int n, m;
vector<pair<int,int>> graph[MAX];
vector<int> from, to;

// 가중치 모두 동일하면 시간초과 나는 구조라 의미없을듯

int dijkstra(int start, int x, int y, bool save, vector<int> &vec) {
    priority_queue<pair<int,int>> pq;
    pq.push({ 0, start });

    vector<int> dist(n + 1, INF);
    dist[start] = 0;

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        cost = -cost;
        pq.pop();

        if (dist[cur] > cost) continue;

        for (auto [nxt, weight] : graph[cur]) {
            if ((cur == x && nxt == y) || (cur == y && nxt == x)) {
                continue;
            }

            int new_cost = cost + weight;

            if (new_cost < dist[nxt]) {
                dist[nxt] = new_cost;
                pq.push({ -new_cost, nxt });
            }
        }
    }

    if (save) vec = dist;

    return dist[n];
}

int main() {
    FastIO

    cin >> n >> m;
    vector<tuple<int,int,int>> edges(m);

    for (int i = 0; i < m; i++) {
        int a, b, t; cin >> a >> b >> t;
        graph[a].emplace_back(b, t);
        graph[b].emplace_back(a, t);
        edges[i] = { a, b, t };
    }

    int late = 0;
    int total = dijkstra(1, -1, -1, true, from);
    dijkstra(n, -1, -1, true, to);

    for (int i = 0; i < m; i++) {
        auto [a, b, w] = edges[i];

        bool chk = (from[a] + w + to[b] == total) || (from[b] + w + to[a] == total);
        if (!chk) continue;

        int t = dijkstra(1, a, b, false, from);
        late = max(late, t);
    }

    int ans = (late < INF) ? (late - total) : -1;
    cout << ans << '\n';

    return 0;
}
