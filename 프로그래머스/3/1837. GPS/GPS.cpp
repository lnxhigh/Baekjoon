#include <bits/stdc++.h>

using namespace std;

const int INF = 10000;
const int MAXT = 101;
const int MAXN = 201;

vector<int> logs;
vector<int> graph[MAXN];
int dp[MAXT][MAXN];

// O(k * n * m)

int dfs(int t, int n) {
    if (t < 0) return 0;
    if (dp[t][n] != -1) return dp[t][n];
    
    if (t == 0) {
        return (logs[0] == n) ? 0 : INF;
    }
    
    int res = INF;

    for (int nxt : graph[n]) {
        int cnt = dfs(t - 1, nxt);
        if (logs[t] != n) cnt++;
        res = min(res, cnt);
    }
    
    return dp[t][n] = res;
}

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {    
    for (auto& x : gps_log) x--;
    logs = gps_log;
    
    for (auto edge : edge_list) {
        int x = edge[0];
        int y = edge[1];
        --x, --y;
        
        graph[x].push_back(y);
        graph[x].push_back(x);
        
        graph[y].push_back(x);
        graph[y].push_back(y);
    }
    
    for (int i = 0; i < MAXT; i++) {
        fill(dp[i], dp[i] + MAXN, -1);
    }
    
    int t = k - 1;
    int x = gps_log.back();
    int ans = dfs(t, x);
    
    logs.clear();
    for (int i = 0; i < MAXN; i++) {
        graph[i].clear();
    }
    
    if (ans >= INF) return -1;
    return ans;
}
