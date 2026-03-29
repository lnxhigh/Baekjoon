#include <bits/stdc++.h>

using namespace std;
const int MAX = 512;

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

int arr[MAX * MAX];
int group[MAX][MAX];
bool chk[MAX * MAX];

int bfs(int x, int y, int t,
    const vector<vector<int>> &land, 
    vector<vector<bool>> &vis
) {
    int m = land.size();
    int n = land[0].size();
    int cnt = 0;
    
    queue<int> q;
    q.push(x * n + y);
    vis[x][y] = true;
    
    while (!q.empty()) {
        int k = q.front();
        q.pop();

        int x = k / n, y = k % n;
        if (land[x][y]) {
            cnt++;
            group[x][y] = t;
        }
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            else if (not land[x][y] or vis[nx][ny]) continue;
            
            q.push({ nx * n + ny });
            vis[nx][ny] = true;
        }
    }
    
    return arr[t] = cnt;
}

int solution(vector<vector<int>> land) {
    int ans = 0;
    int m = land.size();
    int n = land[0].size();
    int t = 1;
    
    vector<vector<bool>> vis(m, vector<bool>(n));
    
    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) {
            if (not land[x][y] or vis[x][y]) continue;
            
            bfs(x, y, t++, land, vis);
        }
    }
    
    for (int i = 0; i < n; i++) {
        int sum = 0;
        
        for (int x = 0; x < m; x++) {
            int t = group[x][i];
            if (t == 0 or chk[t]) continue;
            
            sum += arr[t];
            chk[t] = true;
        }
        
        for (int x = 0; x < m; x++) {
            int t = group[x][i];
            chk[t] = false;
        }
        
        ans = max(ans, sum);
    }
    
    return ans;
}
