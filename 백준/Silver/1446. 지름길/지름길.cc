#include <bits/stdc++.h>
using namespace std;

const int MAX = 10001;
const int INF = 1 << 20;
vector<pair<int,int>> graph[MAX];
int D[MAX];

int main() {
    int N, K; cin >> N >> K;
    
    vector<int> V;
    V.push_back(0); V.push_back(K);
    
    for (int i = 0; i < N; i++) {
        int s, e, l; 
        cin >> s >> e >> l;
        if (e > K || l >= e - s) continue;
        
        graph[s].push_back({ l, e });
        V.push_back(s); V.push_back(e);
    }

    for (int i : V) {
        for (int j : V) {
            if (i < j) graph[i].push_back({ j - i, j });
        }
    }
    
    fill(D, D + MAX, INF);
    D[0] = 0;

    priority_queue<pair<int,int>> pq;
    pq.push({ 0, 0 });

    while (!pq.empty()) {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (D[cur] < cost) continue;

        for (auto [ weight, next ] : graph[cur]) {
            int newCost = cost + weight;
            if (D[next] > newCost) {
                D[next] = newCost;
                pq.push({ -newCost, next });
            }
        }
    }

    cout << D[K] << '\n';
    return 0;
}
