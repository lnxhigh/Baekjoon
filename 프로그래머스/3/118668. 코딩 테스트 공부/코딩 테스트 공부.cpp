#include <bits/stdc++.h>

using namespace std;
const int MAX = 1 << 10;

int dp[MAX][MAX];
bool chk[MAX][MAX];

int dfs(int x, int y, int maxX, int maxY, 
    const vector<vector<int>> &problems
) {
    if (x >= maxX && y >= maxY) return 0;
    if (chk[x][y]) return dp[x][y];
    
    int t = maxX + maxY;
        
    // 공부
    
    if (x < maxX) t = min(t, dfs(x + 1, y, maxX, maxY, problems) + 1);
    if (y < maxY) t = min(t, dfs(x, y + 1, maxX, maxY, problems) + 1);
    
    // 문제 풀이
    
    for (const vector<int> &problem : problems) {
        int minX = problem[0], minY = problem[1];
        if (x < minX || y < minY) continue;
        
        int dx = problem[2];
        int dy = problem[3];
        int dt = problem[4];
        
        int nx = min(x + dx, maxX);
        int ny = min(y + dy, maxY);
        if (nx == x && ny == y) continue;
        
        t = min(t, dfs(nx, ny, maxX, maxY, problems) + dt);
    }
    
    chk[x][y] = true;
    return dp[x][y] = t;
}

int solution(int x, int y, vector<vector<int>> problems) {    
    int maxX = 0, maxY = 0;
    for (const vector<int> &problem : problems) {
        int minX = problem[0], minY = problem[1];
        maxX = max(maxX, minX);
        maxY = max(maxY, minY);
    }
    
    return dfs(x, y, maxX, maxY, problems);
}
