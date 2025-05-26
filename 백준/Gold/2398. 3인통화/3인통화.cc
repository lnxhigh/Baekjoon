#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;
const int INF = 1 << 30;

int n, m;
vector<pair<int,int>> graph[MAX];
int arr[3];
int dist[3][MAX];
int pre[3][MAX];

void djikstra(int k) {
    int start = arr[k];
    priority_queue<pair<int,int>> pq;
    pq.push({ 0, start });

    fill(dist[k], dist[k] + MAX, INF);
    dist[k][start] = 0;

    while (!pq.empty()) {
        auto [cost, x] = pq.top();
        cost = -cost;
        pq.pop();

        if (cost > dist[k][x]) continue;

        for (auto [nxt, w] : graph[x]) {
            int new_cost = cost + w;

            if (new_cost < dist[k][nxt]) {
                pq.push({ -new_cost, nxt });
                dist[k][nxt] = new_cost;
                pre[k][nxt] = x;
            }
        }
    }
}

int main() {
    FastIO

    cin >> n >> m;
    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
        djikstra(i);
    }

    int ans = INF, idx = -1;
    vector<pair<int,int>> links;

    for (int i = 1; i <= n; i++) {
        int sum = dist[0][i] + dist[1][i] + dist[2][i];
        if (sum < ans) ans = sum, idx = i;
    }

    for (int i = 0; i < 3; i++) {
        for (int x = idx; x != arr[i]; x = pre[i][x]) {
            int p = pre[i][x];
            links.push_back({ min(x, p), max(x, p) });
        }
    }
    
    cout << ans << ' ';
    cout << links.size() << '\n';
    for (auto [x, y] : links) cout << x << ' ' << y << '\n';

    return 0;
}
