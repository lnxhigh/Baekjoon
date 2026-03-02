#include <bits/stdc++.h>

using namespace std;
const int MAX = 128;

int par[MAX];

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    else if (x < y) swap(x, y);
    
    par[x] = y;
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int ans = 0;
    iota(par, par + n, 0);
    
    vector<tuple<int,int,int>> edges;
    
    for (auto &cost : costs) {
        int x = cost[0], y = cost[1], w = cost[2];
        edges.push_back({ w, x, y });
    }
    
    sort(edges.begin(), edges.end());
    
    for (auto edge : edges) {
        auto [w, x, y] = edge;
        if (merge(x, y)) ans += w;
    }
    
    return ans;
}
