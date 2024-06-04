#include <bits/stdc++.h>
#define ll long long
#define N_MAX 100001
#define K_MAX 17
using namespace std;

int N, Q;
vector<pair<int,ll>> graph[N_MAX];
bool visited[N_MAX];
int parent[N_MAX][K_MAX];
int depth[N_MAX];
ll cost[N_MAX];

void dfs(int start) {
    for (pair<int,ll> &p : graph[start]) {
        int next = p.first;
        if (visited[next]) continue;
        visited[next] = true;
        
        parent[next][0] = start;
        depth[next] = depth[start] + 1;
        cost[next] = cost[start] + p.second;
        dfs(next);
    }
}

int LCA(int u, int v) {
    if (depth[u] < depth[v]) {
        int tmp = u;
        u = v; v = tmp;
    }

    int diff = depth[u] - depth[v];
    for (int k = 0; k < K_MAX; k++) {
        if (diff & (1 << k)) {
            u = parent[u][k];
        }
    }

    if (u == v) return u;

    for (int k = K_MAX-1; k >= 0; k--) {
        int newU = parent[u][k];
        int newV = parent[v][k];
        if (newU == newV) continue;
        u = newU, v = newV;
    }
    u = parent[u][0], v = parent[v][0];
    return u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int U, V; ll W;
        cin >> U >> V >> W;
        graph[U].push_back({ V, W });
        graph[V].push_back({ U, W });
    }

    int root = 1;
    visited[root] = true;
    dfs(root);

    for (int k = 0; k < K_MAX-1; k++) {
        for (int i = 1; i <= N; i++) {
            parent[i][k+1] = parent[parent[i][k]][k];
        }
    }

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int P;
        int U, V, K;
        cin >> P;
        cin >> U >> V;
        int W = LCA(U, V);

        if (P == 1) {
            ll answer = (cost[U] - cost[W]) + (cost[V] - cost[W]);
            cout << answer << '\n';
        }
        else if (P == 2) {
            cin >> K;
            K--;
            int x = depth[U] - depth[W];
            int y = depth[V] - depth[W];

            int S, diff;
            if (K <= x) { S = U, diff = K; }
            else { S = V, diff = x + y - K; }

            for (int k = 0; k < K_MAX; k++) {
                if (diff & (1 << k)) {
                    S = parent[S][k];        
                }
            }
            cout << S << '\n';
        }
    }

    return 0;
}
