#include <bits/stdc++.h>

using namespace std;
const int MAX = 512;

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };
bool vis[MAX][MAX][4];

int f(int dir, char x) {
    if (x == 'L') return (dir + 1) % 4;
    else if (x == 'R') return (dir + 3) % 4;
    return dir;
}

pair<int,int> mov(int x, int y, int dir, int r, int c) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    
    if (nx < 0) nx += r;
    else if (nx >= r) nx -= r;
    
    if (ny < 0) ny += c;
    else if (ny >= c) ny -= c;
    
    return { nx, ny };
}

void dfs(int x, int y, int dir, const vector<string> &grid, int &cnt) {
    cnt++;
    vis[x][y][dir] = true;

    int r = grid.size();
    int c = grid[0].size();
    int ndir = f(dir, grid[x][y]);
    
    auto [nx, ny] = mov(x, y, ndir, r, c);
    if (vis[nx][ny][ndir]) return;
    
    dfs(nx, ny, ndir, grid, cnt);
}

vector<int> solution(vector<string> grid) {
    vector<int> ans;

    int r = grid.size();
    int c = grid[0].size();
    
    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            for (int dir = 0; dir < 4; dir++) {
                if (vis[x][y][dir]) continue;
                
                int cnt = 0;
                dfs(x, y, dir, grid, cnt);
                ans.push_back(cnt);
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}
