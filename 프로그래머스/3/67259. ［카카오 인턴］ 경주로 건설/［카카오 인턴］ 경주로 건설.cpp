#include <bits/stdc++.h>
using namespace std;
const int MAX = 1 << 5;
const int INF = 1 << 20;

int dist[MAX][MAX][4];
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

int solution(vector<vector<int>> board) {
    int n = board.size();
    priority_queue<tuple<int,int,int,int>> pq;
    int ans = INF;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 and j == 0) {
                continue;
            }
            for (int k = 0; k < 4; k++) {
                dist[i][j][k] = INF;
            }
        }
    }
    
    if (!board[1][0]) dist[1][0][2] = 100, pq.push({ -100, 1, 0, 2 });
    if (!board[0][1]) dist[0][1][3] = 100, pq.push({ -100, 0, 1, 3 });
    
    while (!pq.empty()) {
        auto [cost, x, y, dir] = pq.top();
        cost = -cost;
        pq.pop();
        
        if (x == n - 1 and y == n - 1) ans = min(ans, cost);
        if (dist[x][y][dir] < cost) continue;
        
        for (int ndir = 0; ndir < 4; ndir++) {
            int nx = x + dx[ndir], ny = y + dy[ndir];
            if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
            else if (board[nx][ny]) continue;
            
            bool line = abs(ndir - dir) % 2 == 0;
            int w = line ? 100 : 600;
            int ncost = cost + w;
            
            if (ncost >= dist[nx][ny][ndir]) continue;
            dist[nx][ny][ndir] = ncost;
            pq.push({ -ncost, nx, ny, ndir });
        }
    }
    
    return ans;
}
