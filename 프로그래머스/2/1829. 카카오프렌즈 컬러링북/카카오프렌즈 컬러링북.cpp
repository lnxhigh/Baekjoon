#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

int bfs(int x, int y, vector<vector<int>> &arr, vector<vector<bool>> &vis) {
    int cnt = 0;
    int m = arr.size();
    int n = arr[0].size();
    int num = arr[x][y];
    
    queue<pair<int,int>> q;
    q.push({ x, y });
    vis[x][y] = true;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        cnt++;
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx < 0 or nx >= m or ny < 0 or ny >= n) continue;
            else if (arr[nx][ny] != num or vis[nx][ny]) continue;
            
            q.push({ nx, ny });
            vis[nx][ny] = true;
        }
    }
    
    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> arr) {
    int component = 0, area = 0;
    vector<vector<bool>> vis(m, vector<bool>(n));
    
    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) {
            if (arr[x][y] == 0 or vis[x][y]) continue;
            
            component++;
            int cnt = bfs(x, y, arr, vis);
            area = max(area, cnt);
        }
    }
    
    return { component, area };
}
  