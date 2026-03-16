#include <bits/stdc++.h>

using namespace std;
using Point = pair<int,int>;
const int INF = 1 << 10;

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };
bool vis[10][10][2];

void dfs(Point red, Point blue,
    int turn, int &cnt,
    const vector<vector<int>> &maze
) {
    auto [rx, ry] = red;
    auto [bx, by] = blue;
    
    bool red_fin = (maze[rx][ry] == 3);
    bool blue_fin = (maze[bx][by] == 4);
    bool fin = red_fin and blue_fin;
    
    if (fin) cnt = min(cnt, turn);
    if (fin) return;
    
    int r = maze.size();
    int c = maze[0].size();
    
    if (red_fin) {
        for (int dir = 0; dir < 4; dir++) {
            int nx = bx + dx[dir], ny = by + dy[dir];
            if (nx < 0 or nx >= r or ny < 0 or ny >= c) continue;
            else if (maze[nx][ny] == 5) continue;
            else if (nx == rx and ny == ry) continue;
            else if (vis[nx][ny][1]) continue;
            
            Point nblue = { nx, ny };
            vis[nx][ny][1] = true;
            dfs(red, nblue, turn + 1, cnt, maze);
            vis[nx][ny][1] = false;
        }
    } else if (blue_fin) {
        for (int dir = 0; dir < 4; dir++) {
            int nx = rx + dx[dir], ny = ry + dy[dir];
            if (nx < 0 or nx >= r or ny < 0 or ny >= c) continue;
            else if (maze[nx][ny] == 5) continue;
            else if (nx == bx and ny == by) continue;
            else if (vis[nx][ny][0]) continue;
            
            Point nred = { nx, ny };
            vis[nx][ny][0] = true;
            dfs(nred, blue, turn + 1, cnt, maze);
            vis[nx][ny][0] = false;
        }
    } else {
        for (int rdir = 0; rdir < 4; rdir++) {
            for (int bdir = 0; bdir < 4; bdir++) {
                int nrx = rx + dx[rdir], nry = ry + dy[rdir];
                int nbx = bx + dx[bdir], nby = by + dy[bdir];
                
                if (nrx < 0 or nrx >= r or nry < 0 or nry >= c) continue;
                if (nbx < 0 or nbx >= r or nby < 0 or nby >= c) continue;
                if (maze[nrx][nry] == 5 or maze[nbx][nby] == 5) continue;
                if (nrx == bx and nry == by and nbx == rx and nby == ry) continue; // swap
                if (nrx == nbx and nry == nby) continue; // collision
                if (vis[nrx][nry][0] or vis[nbx][nby][1]) continue;
                
                Point nred = { nrx, nry };
                Point nblue = { nbx, nby };
                vis[nrx][nry][0] = vis[nbx][nby][1] = true;
                dfs(nred, nblue, turn + 1, cnt, maze);
                vis[nrx][nry][0] = vis[nbx][nby][1] = false;
            }
        }
    }
}

int solution(vector<vector<int>> maze) {
    int rx, ry, bx, by;
    
    int r = maze.size();
    int c = maze[0].size();
    
    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            if (maze[x][y] == 1) rx = x, ry = y;
            else if (maze[x][y] == 2) bx = x, by = y;
        }
    }
    
    Point red = { rx, ry };
    Point blue = { bx, by };
    
    int turn = 0;
    int cnt = INF;
    
    vis[rx][ry][0] = vis[bx][by][1] = true;
    dfs(red, blue, turn, cnt, maze);
    
    int ans = 0;
    if (cnt < INF) ans = cnt;
    return ans;
}
