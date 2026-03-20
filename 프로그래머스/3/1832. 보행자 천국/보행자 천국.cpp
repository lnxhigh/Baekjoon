#include <bits/stdc++.h>

using namespace std;

const int MAX = 512;
const int MOD = 20170805;

int dp[MAX][MAX][2];
bool chk[MAX][MAX][2];

int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };

int dfs(int x, int y, int z, const vector<vector<int>> &_map) {
    int m = _map.size();
    int n = _map[0].size();
    
    if (x == m - 1 and y == n - 1) return 1;
    if (chk[x][y][z]) return dp[x][y][z];
    
    int cnt = 0;
    int cell = _map[x][y];
    
    for (int dir = 0; dir <= 1; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        if (cell == 1) continue;
        else if (cell == 2 and dir != z) continue;
        
        cnt += dfs(nx, ny, dir, _map);
    }
    
    chk[x][y][z] = true;
    return dp[x][y][z] = cnt % MOD;
}

int solution(int m, int n, vector<vector<int>> _map) {
    memset(dp, 0, sizeof(dp));
    memset(chk, 0, sizeof(chk));
    return dfs(0, 0, 0, _map);
}
