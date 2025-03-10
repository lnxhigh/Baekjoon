#include <bits/stdc++.h>
using namespace std;
const int MAX = 1 << 20;

vector<int> tree[MAX];
bool vis[MAX];
int deg[MAX];

void dfs(int i, vector<int> &vec) {
    vis[i] = true;
    vec.push_back(i);
    for (int nxt : tree[i]) {
        if (!vis[nxt]) dfs(nxt, vec);
    }
}

bool check(vector<int> &vec, bool flag) {
    int cnt = 0;
    
    for (int node : vec) {
        bool chk = false;
        if (!flag) chk = (node % 2 == deg[node] % 2);
        else chk = (node % 2 != deg[node] % 2);
        
        if (chk) cnt++;
        if (cnt > 1) break;
    }
    
    return cnt == 1;
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer(2);
    for (auto& edge : edges) {
        int x = edge[0];
        int y = edge[1];
        tree[x].push_back(y);
        tree[y].push_back(x);
        deg[x]++, deg[y]++;
    }
    
    for (int node : nodes) {
        if (vis[node]) continue;
        
        vector<int> vec;
        dfs(node, vec);
        
        if (check(vec, false)) answer[0]++;
        if (check(vec, true )) answer[1]++;
    }
    
    return answer;
}
