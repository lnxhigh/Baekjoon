#include <bits/stdc++.h>

using namespace std;
const int MAX = 250005;

vector<int> graph[MAX];
int depth[MAX];

void dfs(int x, int p) {
    for (int nxt : graph[x]) {
        if (nxt == p) continue;
        depth[nxt] = depth[x] + 1;
        dfs(nxt, x);
    }
}

int solution(int n, vector<vector<int>> edges) {    
    for (auto edge : edges) {
        int x = edge[0], y = edge[1];
        x--, y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    dfs(0, -1);
    int u = max_element(depth, depth + n) - depth;
    memset(depth, 0, sizeof(depth));
    
    dfs(u, -1);
    int v = max_element(depth, depth + n) - depth;
    sort(depth, depth + n);
    
    if (depth[n - 1] == depth[n - 2]) return depth[n - 1];
    memset(depth, 0, sizeof(depth));
    
    dfs(v, -1);
    sort(depth, depth + n);
    
    return depth[n - 2];
}
