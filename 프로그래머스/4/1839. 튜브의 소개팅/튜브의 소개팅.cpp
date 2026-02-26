#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MAX = 50;
const ll INF = 1LL << 60;
ll dist[MAX][MAX][MAX * MAX];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

vector<int> solution(int m, int n, int s, vector<vector<int>> timemap) {
    // Init
    ll moves = m * n;
    ll talks = INF;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m * n; k++) {
                dist[i][j][k] = INF;
            }
        }
    }
    
    priority_queue<tuple<ll,ll,ll,ll>> pq;
    pq.push({ 0, 0, 0, 0 });
    dist[0][0][0] = 0;
    
    // Dijkstra
    
    while (!pq.empty()) {
        auto [sum, x, y, depth] = pq.top();
        sum = -sum;
        pq.pop();
        
        // Update answer
        if (x == m - 1 && y == n - 1) {
            if (depth < moves) {
                moves = depth;
                talks = sum;
            } else if (depth == moves) {
                talks = min(talks, sum);
            }
        }
        
        if (dist[x][y][depth] < sum) continue;
        
        // Search
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (timemap[nx][ny] < 0) continue;
            
            ll nsum = sum + timemap[nx][ny];
            ll ndepth = depth + 1;
            
            if (ndepth >= m * n) continue;
            if (nsum > s || nsum >= dist[nx][ny][ndepth]) continue;
            
            dist[nx][ny][ndepth] = nsum;
            pq.push({ -nsum, nx, ny, ndepth });
        }
    }
    
    vector<int> answer(2);
    answer[0] = moves;
    answer[1] = talks;
    
    return answer;
}
