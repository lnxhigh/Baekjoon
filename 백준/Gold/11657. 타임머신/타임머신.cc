#include <bits/stdc++.h>
#define V_MAX 501
#define ll long long
#define INF 1LL << 60
using namespace std;

int V, E;
vector<pair<int,ll>> graph[V_MAX];
ll dist[V_MAX];

void BellmanFord(int start, ll dist[V_MAX]) {
    fill(dist, dist + V_MAX, INF);
    dist[start] = 0;

    // V번 반복
    for (int i = 0; i < V; i++) {
        // 모든 간선 확인
        for (int cur = 1; cur <= V; cur++) {
            for (pair<int,ll> &p : graph[cur]) {
                int next = p.first;
                ll weight = p.second;
                if (dist[cur] >= INF) continue;
                if (dist[next] > dist[cur] + weight) {
                    dist[next] = dist[cur] + weight;
                }
            }
        }
    }
}

bool hasCycle(ll dist[V_MAX]) {
    for (int cur = 1; cur <= V; cur++) {
        for (pair<int,ll> &p : graph[cur]) {
            int next = p.first;
            ll weight = p.second;

            if (dist[cur] >= INF) continue;
            if (dist[next] > dist[cur] + weight) return true;
        }
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> V >> E;

    for (int i = 1; i <= E; i++) {
        int A, B; ll C;
        cin >> A >> B >> C;
        graph[A].push_back({ B, C });
    }

    int start = 1;
    BellmanFord(start, dist);
    
    bool res = hasCycle(dist);
    if (res) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 2; i <= V; i++) {
        ll value = dist[i] >= INF ? -1 : dist[i];
        cout << value << '\n';
    }
    
    return 0;
}
