#include <string>
#include <vector>

using namespace std;

bool dfs(int x, int t,
    const vector<vector<pair<int,int>>> &graph, 
    const vector<bool> &src,  
    const vector<bool> &dst,
    vector<bool> &dp, vector<bool> &vis
) {
    if (vis[x]) return dp[x];
    else vis[x] = true;
    
    if (dst[x]) return dp[x] = true;
    
    for (auto [nxt, w] : graph[x]) {
        if (w > t || src[nxt]) continue;
        bool chk = dfs(nxt, t, graph, src, dst, dp, vis);
        if (chk) return dp[x] = true;
    }
    
    return dp[x] = false;
}

int f(int t, const vector<vector<pair<int,int>>> &graph, 
    const vector<bool> &src,
    const vector<bool> &dst
) {
    int n = graph.size();
    vector<bool> dp(n), vis(n);
    
    for (int x = 0; x < n; x++) {
        if (!src[x] || vis[x]) continue;
        bool chk = dfs(x, t, graph, src, dst, dp, vis);
        if (chk) return x;
    }
    
    return -1;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<vector<pair<int,int>>> graph(n);
    int idx = 0, intensity = 0;
    int low = 1, high = 1;
    
    for (auto path : paths) {
        int x = path[0], y = path[1], w = path[2];
        high = max(high, w);
        
        x--, y--;
        graph[x].emplace_back(y, w);
        graph[y].emplace_back(x, w);
    }
    
    vector<bool> src(n), dst(n);
    for (int x : gates) dst[--x] = true;
    for (int x : summits) src[--x] = true;
    
    while (low <= high) {
        int mid = (low + high) >> 1;
        int x = f(mid, graph, src, dst);
        
        if (x < 0) low = mid + 1;
        else idx = x, intensity = mid, high = mid - 1;
    }
    
    return { ++idx, intensity };
}
