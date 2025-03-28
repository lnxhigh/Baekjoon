#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 10001;
const int INF = 1 << 28;

int N, M, K;
vector<int> markets;
vector<pair<int,int>> graph[MAX];
int dist[5][MAX];

int main() {
    FastIO

    // Input

    cin >> N >> M >> K;

    for (int i = 0; i < K; i++) {
        int x; cin >> x; --x;
        markets.push_back(x);
    }

    for (int i = 0; i < M; i++) {
        int x, y, L; cin >> x >> y >> L; --x, --y;
        graph[x].push_back({ y, L });
        graph[y].push_back({ x, L });
    }

    // Dijkstra

    for (int idx = 0; idx < K; idx++) {
        int* D = dist[idx];
        int market = markets[idx];
        
        fill(D, D + N, INF);
        D[market] = 0;

        priority_queue<pair<int,int>> pq;
        pq.push({ 0, market });
        
        while (!pq.empty()) {
            auto [cost, cur] = pq.top();
            cost = -cost;
            pq.pop();

            if (cost > D[cur]) continue;

            for (auto [nxt, weight] : graph[cur]) {
                int newCost = cost + weight;
                if (newCost < D[nxt]) {
                    D[nxt] = newCost;
                    pq.push({ -newCost, nxt });
                }
            }
        }
    }

    int ans = INF;

    for (int i = 0; i < N; i++) {
        auto iter = find(markets.begin(), markets.end(), i);
        if (iter != markets.end()) continue;

        vector<int> traversal(K);
        for (int j = 0; j < K; j++) {
            traversal[j] = j;
        }

        do {
            int sum = dist[traversal[0]][i] + dist[traversal[K - 1]][i];

            for (int j = 0; j < K - 1; j++) {
                int curIdx = traversal[j];
                int nxtIdx = traversal[j + 1];
                sum += dist[curIdx][markets[nxtIdx]];
            }

            ans = min(ans, sum);

        } while (next_permutation(traversal.begin(), traversal.end()));
    }

    cout << ans << '\n';

    return 0;
}
