#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using pii = pair<int,int>;
const int INF = 1 << 28;

int dijkstra(
    int S, int D,
    const vector<vector<pii>> &graph, 
    set<pii> &shortest, 
    bool almost
) {
        
    const int V = graph.size();
    vector<int> dist(V, INF);
    dist[S] = 0;

    // Track all shortest paths
    vector<vector<int>> P(V);

    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({ 0, S });

    // Check if edges are duplicated to avoid MLE
    set<pii> edges;

    while (!pq.empty()) {
        auto [ cost, cur ] = pq.top();
        pq.pop();

        if (dist[cur] < cost) continue;

        for (auto [ weight, next ] : graph[cur]) {
            // Do not use the shortest path if we are searching for the almost shortest path
            if (almost && shortest.count({ cur, next })) continue;

            int newCost = cost + weight;
            if (dist[next] >= newCost) {
                if (edges.find({ cur, next }) != edges.end()) continue;
                edges.insert({ cur, next });
                
                if (dist[next] > newCost) P[next].clear();
                dist[next] = newCost;
                P[next].push_back(cur);
                pq.push({ newCost, next });
            }
        }
    }

    if (almost) return dist[D];
    
    // Record shortest path
    shortest.clear();
    queue<int> q;
    q.push(D);

    vector<bool> visited(V);
    visited[D] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == S) continue;

        for (int prev : P[cur]) {
            shortest.insert({ prev, cur });
            if (visited[prev]) continue;

            visited[prev] = true;
            q.push(prev);
        }
    }

    shortest.erase({ 0, 0 });

    return dist[D];
}

int main() {
    FastIO
    while (true) {
        int V, E; cin >> V >> E;
        if (V == 0 && E == 0) break;

        int S, D; cin >> S >> D;
        vector<vector<pii>> graph(V);
        set<pii> shortest;

        for (int i = 0; i < E; i++) {
            int u, v, p;
            cin >> u >> v >> p;
            graph[u].push_back({ p, v });
        }

        // shortest dijkstra
        dijkstra(S, D, graph, shortest, false);

        // almost shortest dijkstra
        int dist = dijkstra(S, D, graph, shortest, true);
        if (dist >= INF) dist = -1;
        cout << dist << '\n';
    }

    return 0;
}
