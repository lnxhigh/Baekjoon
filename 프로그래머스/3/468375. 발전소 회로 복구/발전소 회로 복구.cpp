#include <bits/stdc++.h>

using namespace std;

int arr[64][64][16];
int dist[32][32];
bool vis[64][64][16];

int dp[16][1 << 16];
int chk[16][1 << 16];
int masks[16];

int dx[6] = { -1, 0, +1, 0, 0, 0 };
int dy[6] = { 0, -1, 0, +1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, +1, -1 };

void bfs(int idx, int h, const vector<string> &grid, const vector<vector<int>> &panels) {
    int m = grid.size();
    int n = grid[0].size();
    
    queue<tuple<int,int,int,int>> q;
    memset(vis, false, sizeof(vis));
    
    const vector<int> &panel = panels[idx];

    int f = panel[0], r = panel[1], c = panel[2];
    f--, r--, c--;
    
    q.push({ r, c, f, 0 });
    vis[r][c][f] = true;
    
    while (!q.empty()) {
        auto [x, y, z, t] = q.front();
        q.pop();
        
        if (arr[x][y][z] >= 0) {
            dist[idx][arr[x][y][z]] = t;
        }
        
        for (int i = 0; i < 6; i++) {
            if (i >= 4 and grid[x][y] != '@') continue;
            
            int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
            else if (grid[nx][ny] == '#' or vis[nx][ny][nz]) continue;
            
            q.push({ nx, ny, nz, t + 1 });
            vis[nx][ny][nz] = true;
        }
    }
}

int dfs(int x, int bits, int n) {
    if (bits == (1 << n) - 1) return 0;
    if (chk[x][bits]) return dp[x][bits];
    
    int sum = 1 << 20;
    
    for (int nxt = 0; nxt < n; nxt++) {
        if ((bits >> nxt) & 1) continue;
        if ((bits & masks[nxt]) != masks[nxt]) continue;
        
        int tmp = dfs(nxt, bits | (1 << nxt), n) + dist[x][nxt];
        sum = min(sum, tmp);
    }
    
    chk[x][bits] = true;
    return dp[x][bits] = sum;
}

int solution(int h, vector<string> grid, vector<vector<int>> panels, vector<vector<int>> seqs) {
    int k = panels.size();
    memset(arr, -1, sizeof(arr));
    
    for (int i = 0; i < k; i++) {
        const vector<int> &panel = panels[i];
        int f = panel[0], r = panel[1], c = panel[2];
        f--, r--, c--;
        arr[r][c][f] = i;
    }
    
    for (int i = 0; i < k; i++) {
        bfs(i, h, grid, panels);
    }
    
    for (const vector<int> &seq : seqs) {
        int a = seq[0], b = seq[1];
        a--, b--;
        
        int &mask = masks[b];
        mask |= (1 << a);
    }
    
    return dfs(0, 0, k);
}