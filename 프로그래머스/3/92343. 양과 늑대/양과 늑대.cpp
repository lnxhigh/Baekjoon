#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> info, vector<vector<int>> edges) {
    int n = info.size();
    int ans = 0;

    queue<int> q;
    vector<bool> vis(1 << n);
    vector<int> par(n);
    
    q.push(1);
    vis[1] = true;
    
    for (vector<int> edge : edges) {
        int x = edge[0], y = edge[1];
        par[y] = x;
    }
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        int cnt = 0;
        int diff = 0;
        
        for (int i = 0; i < n; i++) {
            bool flag = (x >> i) & 1;
            if (!flag) continue;
            if (!info[i]) cnt++;
            diff += info[i] ? -1 : +1;
        }
        
        for (int i = 0; i < n; i++) {
            bool flag = (x >> i) & 1;
            if (flag) continue;
            if ((~x >> par[i]) & 1) continue;
            if (diff <= 1 and info[i]) continue;
            
            int nxt = x | (1 << i);
            if (vis[nxt]) continue;
            
            q.push(nxt);
            vis[nxt] = true;
        }
        
        ans = max(ans, cnt);
    }
    
    return ans;
}