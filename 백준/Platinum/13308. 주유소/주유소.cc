#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const ll MAX = 2501;
const ll INF = 1LL << 40;

ll n, m;
ll arr[MAX];
vector<pair<ll,ll>> graph[MAX];
ll dist[MAX][MAX];

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++) {
        ll x, y, w; cin >> x >> y >> w; x--, y--;
        graph[x].emplace_back(y, w);
        graph[y].emplace_back(x, w);
    }
}

ll dijkstra() {
    ll ret = INF;

    for (ll i = 0; i < n; i++) {
        fill(dist[i], dist[i] + n, INF);
    }
    
    priority_queue<tuple<ll,ll,ll>> pq;
    pq.push({ 0, 0, 0 });
    dist[0][0] = 0;

    while (!pq.empty()) {
        auto [cost, x, u] = pq.top();
        cost = -cost;
        pq.pop();

        if (x == n - 1) ret = min(ret, cost);
        if (dist[x][u] < cost) continue;

        for (auto [nxt, w] : graph[x]) {
            ll v = arr[nxt] < arr[u] ? nxt : u;
            ll nxt_cost = cost + arr[u] * w;

            if (nxt_cost < dist[nxt][v]) {
                dist[nxt][v] = nxt_cost;
                pq.push({ -nxt_cost, nxt, v });
            }
        }
    }

    return ret;
}

int main() {
    FastIO
    input();
    cout << dijkstra() << '\n';
    return 0;
}
