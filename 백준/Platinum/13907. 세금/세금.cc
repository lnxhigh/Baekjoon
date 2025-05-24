#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;
const int INF = 1 << 30;

int n, m, k;
int s, d;

vector<pair<int,int>> graph[MAX];
int dist[MAX][MAX];

int main() {
    FastIO
    
    cin >> n >> m >> k;
    cin >> s >> d;
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        graph[a].emplace_back(b, w);
        graph[b].emplace_back(a, w);
    }

    priority_queue<tuple<int,int,int>> pq;
    pq.push({ 0, s, 0 });

    for (int i = 1; i <= n; i++) {
        fill(dist[i], dist[i] + n, INF);
    }
    dist[s][0] = 0;

    while (!pq.empty()) {
        auto [cost, cur, cnt] = pq.top();
        cost = -cost;
        pq.pop();

        if (dist[cur][cnt] < cost) continue;

        for (auto [nxt, weight] : graph[cur]) {
            int new_cost = cost + weight;
            if (new_cost < dist[nxt][cnt + 1]) {
                dist[nxt][cnt + 1] = new_cost;
                pq.push({ -new_cost, nxt, cnt + 1 });
            }
        }
    }

    int sum = 0;
    for (int i = 0; i <= k; i++) {
        int p = 0; 
        if (i) cin >> p;
        sum += p;

        int ans = INF;
        for (int x = n - 1, add = (n - 1) * sum; x; x--) {
            ans = min(ans, dist[d][x] + add);
            add -= sum;
        }
        
        cout << ans << '\n';
    }

    return 0;
}
