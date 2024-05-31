#include <bits/stdc++.h>
#define V_MAX 2001
#define INF 10000000000LL
#define ll long long
using namespace std;

int TC;
vector<pair<int,int>> graph[V_MAX];

void dijkstra(int start, ll dist[]) {
    priority_queue<pair<ll,int>> pq; // <cost,node>
    dist[start] = 0;

    pq.push({ 0, start });
    while (!pq.empty()) {
        int cur = pq.top().second;
        ll cost = -pq.top().first;
        pq.pop();

        if (dist[cur] < cost) continue;

        for (pair<ll,int> p : graph[cur]) {
            int next = p.second;
            ll weight = p.first;
            ll newCost = cost + weight;

            if (dist[next] > newCost) {
                dist[next] = newCost;
                pq.push({ -newCost, next });
            }
        }
    }
}

bool check(int S, int G, int H, int E, ll distS[], ll distG[], ll distH[], ll cross) {
    // g -> h or h -> g
    if (distS[E] == distS[G] + cross + distH[E]) return true;
    if (distS[E] == distS[H] + cross + distG[E]) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> TC;
    for (int tc = 0; tc < TC; tc++) {

        // Input and Initilization
        int V, E, T;
        int S, G, H;
        cin >> V >> E >> T;
        cin >> S >> G >> H;

        for (int i = 0; i < V_MAX; i++) graph[i].clear();
        int X[V_MAX];
        ll distS[V_MAX], distG[V_MAX], distH[V_MAX];
        for (int i = 0; i < V_MAX; i++) {
            distS[i] = distG[i] = distH[i] = INF;
        }

        for (int i = 0; i < E; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            graph[a].push_back({ d, b });
            graph[b].push_back({ d, a });
        }

        ll cross = 0;
        for (pair<ll,int> p : graph[G]) {
            if (p.second == H) {
                cross = p.first;
                break;
            }
        }

        for (int i = 0; i < T; i++) {
            cin >> X[i];
        }

        // Shortest Path
        dijkstra(S, distS);
        dijkstra(G, distG);
        dijkstra(H, distH);

        // Answer
        vector<int> res;
        for (int i = 0; i < T; i++) {
            if (check(S, G, H, X[i], distS, distG, distH, cross)) res.push_back(X[i]);
        }

        sort(res.begin(), res.end());
        for (int i : res) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}
