#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const int MAX = 10001;
const ll INF = 1LL << 60;

int N, M, K;
vector<pair<int,ll>> graph[MAX];
ll D[MAX][21];

int main() {
    FastIO

    // Input
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y; --x, --y;
        ll w; cin >> w;
        
        graph[x].push_back({ y, w });
        graph[y].push_back({ x, w });
    }

    // Initialize
    priority_queue<tuple<ll,int,int>> pq;
    pq.push({ 0, 0, 0 });
    for (int i = 0; i < N; i++) {
        fill(D[i], D[i] + K + 1, INF);
    }
    D[0][0] = 0;

    // Dijkstra
    while (!pq.empty()) {
        auto [cost, cur, cnt] = pq.top();
        cost = -cost;
        pq.pop();

        if (D[cur][cnt] < cost) {
            continue;
        }

        if (cnt < K && cost < D[cur][cnt + 1]) {
            D[cur][cnt + 1] = cost;
            pq.push({ -cost, cur, cnt + 1 });
        }

        for (auto [nxt, weight] : graph[cur]) {
            if (cost + weight < D[nxt][cnt]) {
                D[nxt][cnt] = cost + weight;
                pq.push({ -(cost + weight), nxt, cnt });
            }
            if (cnt < K && cost < D[nxt][cnt + 1]) {
                D[nxt][cnt + 1] = cost;
                pq.push({ -cost, nxt, cnt + 1 });
            }
        }
    }
    
    cout << D[N - 1][K] << '\n';
    return 0;
}
