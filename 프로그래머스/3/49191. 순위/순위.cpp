#include <bits/stdc++.h>
using namespace std;
const int MAX = 1 << 7;

void dfs(int x, const vector<vector<int>> &graph, vector<bool> &vis, int &cnt) {
    cnt++;
    vis[x] = true;
    
    for (int nxt : graph[x]) {
        if (!vis[nxt]) {
            dfs(nxt, graph, vis, cnt);
        }
    }
}

int solution(int n, vector<vector<int>> results) {
    int ans = 0;
    vector<vector<int>> win(n), lose(n);
    
    for (vector<int> &result : results) {
        int &x = result[0], &y = result[1];
        x--, y--;
        
        win[x].push_back(y);
        lose[y].push_back(x);
    }
    
    for (int i = 0; i < n; i++) {
        int sum = 0;
        vector<bool> x(n), y(n);
        
        dfs(i, win, x, sum);
        dfs(i, lose, y, sum);
        if (sum == n + 1) ans++;
    }
    
    return ans;
}

