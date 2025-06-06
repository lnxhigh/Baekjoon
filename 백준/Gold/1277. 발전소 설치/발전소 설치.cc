#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const int MAX = 1 << 10;

int n, w;
double m;

vector<pair<ll,ll>> location;

double cache[MAX][MAX];
double dist[MAX];

int main() {
    FastIO

    // Input

    cin >> n >> w >> m;
    location.resize(n);
    for (auto& [x, y] : location) cin >> x >> y;

    // Preprocess

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            auto [x, y] = location[i];
            auto [a, b] = location[j];

            double dx = x - a, dy = y - b;
            cache[i][j] = sqrt(dx*dx + dy*dy);
        }
    }
    
    for (int i = 0; i < w; i++) {
        int x, y; cin >> x >> y; --x, --y;
        cache[x][y] = cache[y][x] = 0;
    }

    // Dijkstra

    priority_queue<pair<double,int>> pq;
    pq.push({ 0, 0 });

    fill(dist, dist + MAX, 1e18);
    dist[0] = 0;

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        cost = -cost;
        pq.pop();

        if (cost > dist[cur]) continue;

        for (int nxt = 0; nxt < n; nxt++) {
            if (nxt == cur) continue;

            double add = cache[cur][nxt];
            if (add > m) continue;

            double newCost = cost + add;
            if (newCost < dist[nxt]) dist[nxt] = newCost, pq.push({ -newCost, nxt });
        }
    }

    int ans = dist[n - 1] * 1000;
    cout << ans << '\n';
    return 0;
}
