#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100001;
const long long INF = 1LL << 60;

int N, M, K, S, T;
vector<pair<int,long long>> graph[MAX], inverse[MAX];

long long D[MAX][11];
bool vis[MAX][11];

long long dfs(int n, int k) {
    if (vis[n][k]) return D[n][k];

    D[n][k] = -INF;
    vis[n][k] = true;

    // ski
    for (auto [i, t] : graph[n]) {
        D[n][k] = max(D[n][k], dfs(i, k) + t);
    }
    if (k == 0) return D[n][k];

    // lift
    for (auto [i, t] : inverse[n]) {
        D[n][k] = max(D[n][k], dfs(i, k - 1));
    }

    return D[n][k];
}

int main() {
    FastIO
    cin >> N >> M >> K >> S >> T;
    
    while (M--) {
        int a, b;
        long long t;
        cin >> a >> b >> t;
        graph[a].push_back({ b, t });
        inverse[b].push_back({ a, t });
    }

    for (int i = 0; i < MAX; i++) {
        fill(D[i], D[i] + 11, -INF);
    }
    
    D[T][0] = 0;
    vis[T][0] = true;
    
    long long ans = dfs(S, K);
    if (ans < 0) ans = -1;
    cout << ans << '\n';
    return 0;
}
