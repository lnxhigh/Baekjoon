#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int V, E;
const int MAX = 1 << 11;
bool graph[MAX][MAX];
long long sum[MAX][MAX];

int main() {
    FastIO
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int u, v; cin >> u >> v;
        graph[u][v] = true;
    }

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            if (graph[i][j]) sum[i][j]++;
        }
    }

    long long res = 0;
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (!graph[i][j]) continue;
            res += sum[i-1][V] - sum[i-1][j];
            res += sum[V][j-1] - sum[i][j-1];
        }
    }

    res /= 2;
    cout << res << '\n';
    return 0;
}
