#include <bits/stdc++.h>
#define N_MAX 40001
#define K_MAX 16
using namespace std;

int N, Q;
vector<pair<int,int>> graph[N_MAX];

int parent[N_MAX][K_MAX];
int depth[N_MAX];
int dist[N_MAX];
bool visited[N_MAX];

void DFS(int cur) {
    for (const pair<int,int> &p : graph[cur]) {
        int next = p.first;
        if (visited[next]) continue;
        
        visited[next] = true;
        depth[next] = depth[cur] + 1;
        dist[next] = dist[cur] + p.second;
        parent[next][0] = cur;
        
        DFS(next);
    }    
}

int LCA(int u, int v) {
    // Swap
    if (depth[u] < depth[v]) {
        int tmp = u;
        u = v; v = tmp;
    }

    // 같은 높이가 되도록 조정
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    // 초기 세팅
    int root = 1;
    visited[root] = true;
    DFS(root);

    // 희소 행렬 채우기
    for (int k = 0; k < K_MAX-1; k++) {
        for (int i = 1; i <= N; i++) {
            parent[i][k+1] = parent[parent[i][k]][k];
        }
    }

    // 쿼리 수행
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int U, V, W;
        cin >> U >> V;
        W = LCA(U, V);
        int answer = (dist[U] - dist[W]) + (dist[V] - dist[W]);
        cout << answer << '\n';
    }

    return 0;
}
