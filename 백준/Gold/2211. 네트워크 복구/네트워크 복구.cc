#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int V, E;
const int MAX = 1 << 10;
const int INF = 1 << 28;
vector<pair<int,int>> graph[MAX];
int dist[MAX];
int P[MAX];

void dijkstra(int start) {
    fill(dist, dist + V, INF);
    dist[start] = 0;

    fill(P, P + V, -1);

    priority_queue<pair<int,int>> pq;
    pq.push({ 0, start });
    
    while (!pq.empty()) {
        pair<int,int> top = pq.top();
        int cur = top.second;
        int cost = -top.first;
        pq.pop();

        if (dist[cur] < cost) continue;

        for (auto p : graph[cur]) {
            int next = p.second;
            int weight = p.first;
            int newCost = cost + weight;

            if (newCost < dist[next]) {
                dist[next] = newCost;
                P[next] = cur;
                pq.push({ -newCost, next });
            }
        }
    }
}

int main() {
    FastIO
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        --A; --B;
        graph[A].push_back({ C, B });
        graph[B].push_back({ C, A });
    }

    dijkstra(0);

    int cnt = 0;
    for (int i = 1; i < V; i++) {
        if (P[i] != -1) cnt++;
    }
    cout << cnt << '\n';

    for (int i = 1; i < V; i++) {
        if (P[i] != -1) cout << i+1 << ' ' << P[i]+1 << '\n';
    }
    
    return 0;
}
