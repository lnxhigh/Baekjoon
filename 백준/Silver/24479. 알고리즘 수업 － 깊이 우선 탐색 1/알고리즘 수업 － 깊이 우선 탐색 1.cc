#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
set<int> graph[MAX];
int visited[MAX];
int T = 0;

void dfs(int cur) {
    visited[cur] = ++T;
    for (int next : graph[cur]) {
        if (!visited[next]) dfs(next);
    }
}

int main() {
    int V, E, R;
    cin >> V >> E >> R;

    for (int i = 0; i < E; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        graph[u].insert(v);
        graph[v].insert(u);
    }

    dfs(--R);

    for (int i = 0; i < V; i++) {
        cout << visited[i] << '\n';
    }

    return 0;
}
