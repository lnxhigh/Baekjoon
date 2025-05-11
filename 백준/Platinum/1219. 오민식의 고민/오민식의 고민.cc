#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const ll MAX = 100;
const ll INF = 1LL << 50;

ll n, m, s, e;
tuple<ll,ll,ll> edges[MAX];

ll arr[MAX];
ll dist[MAX];

int main() {
    FastIO

    cin >> n >> s >> e >> m;

    for (int i = 0; i < m; i++) {
        ll x, y, w; cin >> x >> y >> w;
        edges[i] = { x, y, w };
    }

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Bellman-Ford

    fill(dist, dist + n, INF);
    dist[s] = -arr[s];

    for (int k = 0; k < (n * 2); k++) {
        for (int i = 0; i < m; i++) {
            auto [x, y, w] = edges[i];
            if (dist[x] == INF) continue;
            
            if (dist[x] + w - arr[y] < dist[y]) {
                dist[y] = (k < n - 1) ? dist[x] + w - arr[y] : -INF;
            }
        }
    }
    
    if (dist[e] >= INF) cout << "gg" << '\n';
    else if (dist[e] <= -INF) cout << "Gee" << '\n';
    else cout << -dist[e] << '\n';

    return 0;
}
