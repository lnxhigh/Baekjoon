#include <bits/stdc++.h>

using namespace std;
const int MAX = 100001;

vector<int> graph[MAX];
int dp[MAX][2];
bool chk[MAX][2];

int dfs(int cur, int prv, bool flag) {
    if (chk[cur][flag]) return dp[cur][flag];
    
    int cnt = flag;
    
    for (int nxt : graph[cur]) {
        if (nxt == prv) continue;
        
        int on = dfs(nxt, cur, true);
        int off = dfs(nxt, cur, false);
        cnt += flag ? min(on, off) : on;
    }

    chk[cur][flag] = true;
    return dp[cur][flag] = cnt;
}

int solution(int n, vector<vector<int>> edges) {
    for (vector<int> edge : edges) {
        int x = edge[0] - 1;
        int y = edge[1] - 1;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    return min(dfs(0, -1, true), dfs(0, -1, false));
}
