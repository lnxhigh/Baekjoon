#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAXN = 101, MAXM = 10001;
const int INF = 1 << 28;

int T;
int N, M, K;

vector<tuple<int,int,int>> graph[MAXN];
int D[MAXN][MAXM];

int dijkstra() {
    int ret = INF;

    for (int i = 0; i < N; i++) {
        fill(D[i], D[i] + MAXM, INF);
    }
    
    priority_queue<tuple<int,int,int>> pq;
    pq.push({ 0, 0, 0 });
    D[0][0] = 0;

    while (!pq.empty()) {
        auto [total, cur, money] = pq.top();
        total = -total;
        pq.pop();

        if (cur == N - 1) {
            ret = min(ret, total);
            continue;
        }
        else if (total > D[cur][money] || total >= ret) {
            continue;
        }

        for (auto [t, m, nxt] : graph[cur]) {
            if (money + m > M) continue;
            
            int newT = total + t;
            int newM = money + m;

            if (newT < D[nxt][newM]) {
                D[nxt][newM] = newT;
                pq.push({ -newT, nxt, newM });

                newM++;
                while (newM <= M && D[nxt][newM] > newT) D[nxt][newM++] = newT;
            }
        }
    }

    return ret;
}

int main() {
    FastIO
    cin >> T;
    cin >> N >> M >> K;
    
    for (int i = 0; i < K; i++) {
        int u, v, c, d; 
        cin >> u >> v >> c >> d;
        --u, --v;
        graph[u].push_back({ d, c, v });
    }
    
    for (int i = 0; i < N; i++) {
        if (graph[i].empty()) continue;
        sort(graph[i].begin(), graph[i].end());
    }

    int ans = dijkstra();
    if (ans >= INF) cout << "Poor KCM" << '\n';
    else cout << ans << '\n';

    return 0;
}
