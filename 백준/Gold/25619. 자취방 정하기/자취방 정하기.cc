#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int64 MAX = 200001;
const int64 INF = 1LL << 60;

int64 V, E;
vector<pair<int64,int64>> graph[MAX];
int64 T;

bool  M[MAX];
int64 D[MAX];

void input() {
    cin >> V >> E;

    for (int64 i = 0; i < E; i++) {
        int64 u, v, a, b;
        cin >> u >> v; --u, --v;
        cin >> a >> b;
        int64 w = a + b;
        
        if (w < 0) M[u] = M[v] = true;
        w = max(w, 0LL);

        graph[u].push_back({ w, v });
        graph[v].push_back({ w, u });
    }

    cin >> T; T *= 2;
}

bool dijkstra(int start) {
    priority_queue<pair<int64,int64>> pq;
    fill(D, D + V, INF);
    
    pq.push({ 0, 0 });
    D[start] = 0;

    bool flag = false;

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        cost = -cost;
        pq.pop();

        if (M[cur]) flag = true;
        if (D[cur] < cost) continue;

        for (auto [weight, next] : graph[cur]) {
            if (cost + weight < D[next]) {
                D[next] = cost + weight;
                pq.push({ -(cost + weight), next });
            }
        }
    }

    return flag;
}

int main() {
    FastIO
    input();
    bool flag = dijkstra(0);
    
    vector<int64> all;
    all.reserve(V);

    for (int i = 1; i < V; i++) {
        if (D[i] >= INF) continue;
        if (flag || D[i] <= T) all.push_back(i);
    }
    
    cout << all.size() << '\n';
    for (auto i : all) cout << i + 1 << ' ';

    return 0;
}
