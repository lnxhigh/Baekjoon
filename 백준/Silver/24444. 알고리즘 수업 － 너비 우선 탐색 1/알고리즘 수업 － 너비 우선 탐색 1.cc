#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
set<int> graph[MAX];
int visited[MAX];
int T = 0;

void bfs(int start) {
    visited[start] = ++T;
    
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next : graph[cur]) {
            if (!visited[next]) {
                visited[next] = ++T;
                q.push(next);
            }
        }
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

    bfs(--R);

    for (int i = 0; i < V; i++) {
        cout << visited[i] << '\n';
    }

    return 0;
}
