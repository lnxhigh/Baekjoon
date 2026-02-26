#include <bits/stdc++.h>

using namespace std;
using XY = pair<int,int>;
using Edge = pair<XY,XY>;

XY par[301][301];
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

pair<int,int> find(XY node) {
    auto [x, y] = node;
    auto [px, py] = par[x][y];
    if (x == px && y == py) return { x, y };
    
    return par[x][y] = find(par[x][y]);
}

bool merge(XY from, XY to) {
    XY a = find(from);
    XY b = find(to);
    
    bool cycle = (a.first == b.first && a.second == b.second);
    if (cycle) return false;
    
    if (a > b) par[a.first][a.second] = b;
    else if (a < b) par[b.first][b.second] = a;
    return true;
}

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    
    int n = land.size();
    vector<pair<int, Edge>> edges;
    
    // Graph
    
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            par[x][y] = { x, y };
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                
                int diff = abs(land[x][y] - land[nx][ny]);
                int weight = diff > height ? diff : 0;
                
                XY from = { x, y }, to = { nx, ny };
                Edge edge = { from, to };
                edges.push_back({ weight, edge });
            }
        }
    }
    
    // Kruskal
    
    int ans = 0;
    sort(edges.begin(), edges.end());
    
    for (auto [weight, edge] : edges) {
        auto [from, to] = edge;
        bool chk = merge(from, to);
        if (chk) ans += weight;
    }
    
    return ans;
}
