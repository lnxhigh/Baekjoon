#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int V, E;
const int MAX = 100000;
vector<int> graph[MAX];
bool visited[MAX];

void dfs(int cur, vector<int> &v) {
    visited[cur] = true;
    v.push_back(cur);

    for (int next : graph[cur]) {
        if (!visited[next]) dfs(next, v);
    }
}

int main() {
    FastIO
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int res = 0, component = 0;
    for (int i = 0; i < V; i++) {
        if (visited[i]) continue;
        component++;
        
        vector<int> v;
        dfs(i, v);

        int edges = 0;
        for (int k : v) {
            edges += graph[k].size();
        }
        edges /= 2;

        int s = v.size();
        res += edges - (s - 1);
    }

    res += component - 1;
    cout << res << '\n';
    return 0;
}
