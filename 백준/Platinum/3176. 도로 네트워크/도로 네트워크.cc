#include <bits/stdc++.h>
#define INF 1LL << 60
#define ll long long
#define N_MAX 100000
#define K_MAX 17
using namespace std;

int N, Q;
vector<pair<int,ll>> graph[N_MAX];
int parent[N_MAX][K_MAX];
int depth[N_MAX];
bool visited[N_MAX];

ll minDist[N_MAX][K_MAX];
ll maxDist[N_MAX][K_MAX];

void dfs(int start) {
    for (pair<int,ll> p : graph[start]) {
        int next = p.first;
        if (visited[next]) continue;
        visited[next] = true;
        
        depth[next] = depth[start] + 1;
        parent[next][0] = start;
        minDist[next][0] = p.second;
        maxDist[next][0] = p.second;
        
        dfs(next);
    }
}

int LCA(int u, int v) {
    // Swap
    if (depth[u] < depth[v]) {
        int tmp = u;
        u = v;
        v = tmp;
    }

    // diff 만큼 끌어올리기
    int diff = depth[u] - depth[v];
    for (int k = 0; k < K_MAX; k++) {
        if (diff & (1 << k)) u = parent[u][k];
    }
    
    // LCA 체크
    if (u == v) return u;

    // LCA 찾기
    for (int k = K_MAX-1; k >= 0; k--) {
        int newU = parent[u][k];
        int newV = parent[v][k];
        if (newU == newV) continue;
        
        u = newU, v = newV;
    }
    u = parent[u][0], v = parent[v][0];

    return u;
}

pair<ll,ll> dist(int descendant, int ancestor) {
    ll minValue = INF;
    ll maxValue = 0;

    int diff = depth[descendant] - depth[ancestor];
    for (int k = 0; k < K_MAX; k++) {
        if (diff & (1 << k)) {
            minValue = min(minValue, minDist[descendant][k]);
            maxValue = max(maxValue, maxDist[descendant][k]);
            descendant = parent[descendant][k];
        }
    }

    return { minValue, maxValue };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int A, B; ll C;
        cin >> A >> B >> C;
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }

    int root = 1;
    visited[root] = true;
    dfs(root);

    for (int k = 0; k < K_MAX-1; k++) {
        for (int i = 1; i <= N; i++) {
            parent[i][k+1] = parent[parent[i][k]][k];
            minDist[i][k+1] = min(minDist[i][k], minDist[parent[i][k]][k]);
            maxDist[i][k+1] = max(maxDist[i][k], maxDist[parent[i][k]][k]);
        }
    }

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int U, V;
        cin >> U >> V;
        int W = LCA(U, V);
        pair<ll,ll> pathU = dist(U, W);
        pair<ll,ll> pathV = dist(V, W);

        ll minValue = min(pathU.first, pathV.first);
        ll maxValue = max(pathU.second, pathV.second);
        cout << minValue << ' ' << maxValue << '\n';
    }

    return 0;
}
