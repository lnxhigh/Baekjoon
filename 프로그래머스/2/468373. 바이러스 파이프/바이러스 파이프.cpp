#include <bits/stdc++.h>

using namespace std;
const int MAX = 128;

vector<pair<int,int>> graph[MAX];

int bfs(int n, int x, vector<int> &types) {
    // Infections
    vector<int> nodes = { x };

    // Expansion
    for (int type : types) {
        queue<int> q;
        vector<bool> vis(n);

        for (int node : nodes) {
            q.push(node);
            vis[node] = true;
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (auto [nxt, t] : graph[cur]) {
                if (vis[nxt] || type != t) continue;
                q.push(nxt);
                vis[nxt] = true;
                nodes.push_back(nxt);
            }
        }
    }
    
    return (int) nodes.size();
}

void dfs(int n, int x, int k, vector<int> &types, int &cnt) {
    if (types.size() == k) {
        int size = bfs(n, x, types);
        cnt = max(cnt, size);
        return;
    }
    
    for (int i = 1; i <= 3; i++) {
        types.push_back(i);
        dfs(n, x, k, types, cnt);
        types.pop_back();
    }
}

int solution(int n, int x, vector<vector<int>> edges, int k) {
    for (auto edge : edges) {
        int x = edge[0], y = edge[1], type = edge[2];
        graph[x].emplace_back(y, type);
        graph[y].emplace_back(x, type);
    }

    int ans = 0;
    vector<int> types;
    dfs(n, x, k, types, ans);
    
    return ans;
}
