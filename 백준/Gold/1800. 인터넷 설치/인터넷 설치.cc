#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;
const int INF = (1 << 30) - 1;

int V, E, K;
vector<pair<int,int>> graph[MAX];
int D[MAX][MAX];

int main() {
    FastIO

    // Input     
    cin >> V >> E >> K;
    for (int i = 0; i < E; i++) {
        int x, y, L; cin >> x >> y >> L; --x, --y;
        graph[x].push_back({ y, L });
        graph[y].push_back({ x, L });
    }

    // Dijkstra
    int ans = INF;
    priority_queue<tuple<int,int,int>> pq;
    pq.push({ 0, 0, 0 });

    for (int i = 0; i < V; i++) {
        fill(D[i], D[i] + V, INF);
    }
    D[0][0] = 0;

    while (!pq.empty()) {
        auto [cost, cur, cnt] = pq.top();
        cost = -cost;
        pq.pop();

        if (cur == V - 1) ans = min(ans, cost);
        if (cost > D[cur][cnt]) continue;

        for (auto [nxt, len] : graph[cur]) {
            int newCost = max(cost, len);
            if (newCost < D[nxt][cnt]) {
                D[nxt][cnt] = newCost;
                pq.push({ -newCost, nxt, cnt });
            }

            if (cnt < K && cost < D[nxt][cnt + 1]) {
                D[nxt][cnt + 1] = cost;
                pq.push({ -cost, nxt, cnt + 1 });
            }
        }
    }

    if (ans >= INF) ans = -1;
    cout << ans << '\n';

    return 0;
}
