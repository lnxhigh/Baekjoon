#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int INF = 1 << 27;
const int MAX = 1 << 7;

int V, E;
vector<pair<int,int>> graph[MAX];
int J, S;

int A[MAX], B[MAX];

void input() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }
    cin >> J >> S;

    for (int i = 1; i <= V; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
}

void dijkstra(int x, int D[MAX]) {
    priority_queue<pair<int,int>> pq;
    fill(D + 1, D + V + 1, INF);

    D[x] = 0;
    pq.push({ 0, x });
    
    while (!pq.empty()) {
        auto [dist, cur] = pq.top();
        dist = -dist;
        pq.pop();

        if (D[cur] < dist) continue;
        for (auto [nxt, weight] : graph[cur]) {
            int newDist = dist + weight;
            if (newDist < D[nxt]) {
                D[nxt] = newDist;
                pq.push({ -newDist, nxt });
            }
        }
    }
}

int solve() {
    int ret = -1;
    int len = INF;
    int dist = INF;

    for (int x = 1; x <= V; x++) {
        if (x == J || x == S) continue;
        len = min(len, A[x] + B[x]);
    }

    for (int i = (int) graph[J].size() - 1; i >= 0; i--) {
        auto [x, weight] = graph[J][i];
        if (x == J || x == S) continue;
        else if (weight + B[x] > len) continue;
        else if (weight > len - weight) continue;
        else if (weight <= dist) ret = x, dist = weight;
    }

    return ret;
}

int main() {
    FastIO
    input();
    dijkstra(J, A);
    dijkstra(S, B);
    
    int ans = solve();
    cout << ans << '\n';
    return 0;
}
