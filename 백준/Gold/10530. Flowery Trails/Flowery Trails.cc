#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 10001;
const int INF = 1'000'000'000;

int V, E;
vector<pair<int,int>> graph[MAX];
int S[MAX], T[MAX];

void input() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int x, y, w; cin >> x >> y >> w;
        graph[x].push_back({ y, w });
        graph[y].push_back({ x, w });
    }
}

void dijkstra(int x, int* D) {
    fill(D, D + V, INF);
    D[x] = 0;

    priority_queue<pair<int,int>> pq;
    pq.push({ 0, x });
    
    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        cost = -cost;
        pq.pop();

        if (cost > D[cur]) continue;

        for (auto [nxt, weight] : graph[cur]) {
            int newCost = cost + weight;
            if (newCost < D[nxt]) {
                D[nxt] = newCost;
                pq.push({ -newCost, nxt });
            }
        }
    }
}

int main() {
    FastIO
    input();
    dijkstra(0, S);
    dijkstra(V - 1, T);

    long long ans = 0;
    int minDist = S[V - 1];

    for (int cur = 0; cur < V; cur++) {
        for (auto [nxt, weight] : graph[cur]) {
            if (cur >= nxt) continue; // For all edges
            
            // if the edge can be used as a part of a shortest path
            bool chk = S[cur] + weight + T[nxt] == minDist;
            chk |= S[nxt] + weight + T[cur] == minDist;
            
            if (chk) ans += (long long) weight;
        }
    }

    ans *= 2;
    cout << ans << '\n';

    return 0;
}
