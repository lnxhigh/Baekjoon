#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

int solution(int n, int src, int dst, vector<vector<int>> roads, vector<int> traps) {
    vector<vector<tuple<int,int,bool>>> graph(n);
    vector<vector<int>> dist(n, vector<int>(1 << traps.size(), INF));
    vector<int> chk(n, -1);
    int t = INF;
    
    src--, dst--;
    
    for (vector<int> &road : roads) {
        int &p = road[0], &q = road[1], &s = road[2];
        p--, q--;
        
        graph[p].emplace_back(q, s, true);
        graph[q].emplace_back(p, s, false);
    }
    
    for (int i = 0; i < traps.size(); i++) {
        int &trap = traps[i];
        chk[--trap] = i;
    }
    
    priority_queue<tuple<int,int,int>> pq;
    pq.push({ 0, src, 0 });
    dist[src][0] = 0;
    
    while (!pq.empty()) {
        auto [cost, x, bits] = pq.top();
        cost = -cost;
        pq.pop();
        
        if (x == dst) t = min(t, cost);
        if (dist[x][bits] < cost) continue;
        
        for (auto [nxt, w, flag] : graph[x]) {
            bool x_active = (chk[x] != -1) && ((bits >> chk[x]) & 1);
            bool nxt_active = (chk[nxt] != -1) && ((bits >> chk[nxt]) & 1);
            bool rev = x_active ^ nxt_active;
            if (!(flag ^ rev)) continue;
            
            int nbits = (chk[nxt] == -1) ? bits : bits ^ (1 << chk[nxt]);
            int ncost = cost + w;
            
            if (dist[nxt][nbits] <= ncost) continue;
            dist[nxt][nbits] = ncost;
            pq.push({ -ncost, nxt, nbits });
        }
    }

    return t;
}
