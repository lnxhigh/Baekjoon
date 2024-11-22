#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int R, C, K, W;
int Room[20][20];
bool Wall[20][20][20][20];

int Heatmap[20][20][20][20];
int HeatmapAll[20][20];

int Temp[20][20];
int Delta[20][20];

vector<pair<int,int>> H, P;
int dx[5] = { 0, -1, 0, +1, 0 };
int dy[5] = { 0, 0, -1, 0, +1 };
int dir[6] = { 0, 4, 2, 1, 3, 5 };

void input() {
    cin >> R >> C >> K;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int d; cin >> d;
            if (d == 0) continue;

            int newDir = dir[d];
            Room[i][j] = newDir;
            
            vector<pair<int,int>> &V = (d <= 4) ? H : P; 
            V.push_back({ i, j });
        }
    }

    cin >> W;
    for (int i = 0; i < W; i++) {
        int x, y, t; cin >> x >> y >> t;
        --x, --y;
        if (!t) Wall[x][y][x-1][y] = Wall[x-1][y][x][y] = true;
        else    Wall[x][y][x][y+1] = Wall[x][y+1][x][y] = true;
    }
}

bool inside(int x, int y) {
    if (x < 0 || x >= R || y < 0 || y >= C) {
        return false;
    }
    return true;
}

void dfs(pair<int,int> cur, const pair<int,int> &start, int t) {
    if (t == 0) return;

    auto [sx, sy] = start;
    auto [x, y] = cur;
    Heatmap[sx][sy][x][y] = t;

    int d = Room[sx][sy];
    int l = (d + 1) % 4, r = (d + 3) % 4;
    if (l == 0) l = 4; if (r == 0) r = 4;

    int nx = x + dx[d], ny = y + dy[d];
    int lx = x + dx[l], ly = y + dy[l];
    int rx = x + dx[r], ry = y + dy[r];

    // Straight
    if (inside(nx, ny)) {
        if (!Wall[x][y][nx][ny]) {
            dfs({ nx, ny }, start, t - 1);
        }
    }
    
    // Left
    if (inside(lx + dx[d], ly + dy[d])) {
        if (!Wall[x][y][lx][ly] && !Wall[lx][ly][lx + dx[d]][ly + dy[d]]) {
            dfs({ lx + dx[d], ly + dy[d] }, start, t - 1);      
        }
    }
    
    // Right
    if (inside(rx + dx[d], ry + dy[d])) {
        if (!Wall[x][y][rx][ry] && !Wall[rx][ry][rx + dx[d]][ry + dy[d]]) {
            dfs({ rx + dx[d], ry + dy[d] }, start, t - 1);      
        }
    }
}

void init() {
    // Fill Heatmap
    for (auto start : H) {
        auto [x, y] = start;
        int d = Room[x][y];
        pair<int,int> cur = { x + dx[d], y + dy[d] };
        dfs(cur, start, 5);
    }

    // Aggregate Heatmap
    for (auto [x, y] : H) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                HeatmapAll[i][j] += Heatmap[x][y][i][j];
            }
        }
    }
}

void heat() {
    for (int x = 0; x < R; x++) {
        for (int y = 0; y < C; y++) {
            Temp[x][y] += HeatmapAll[x][y];
        }
    }
}

void diffuse() {
    memset(Delta, 0, sizeof(Delta));
    
    for (int x = 0; x < R; x++) {
        for (int y = 0; y < C; y++) {
            // update per [x, y]
            for (int d = 1; d <= 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (!inside(nx, ny) || Wall[x][y][nx][ny]) continue;
            
                // Calculate the amount
                if (Temp[x][y] <= Temp[nx][ny]) continue;
                int diff = (Temp[x][y] - Temp[nx][ny]) / 4;
                
                Delta[x][y] -= diff;
                Delta[nx][ny] += diff;
            }
        }
    }

    for (int x = 0; x < R; x++) {
        for (int y = 0; y < C; y++) {
            Temp[x][y] += Delta[x][y];
        }
    }
}

void cool() {
    for (int i = 1; i < R - 1; i++) {
        if (Temp[i][0]) Temp[i][0]--;
        if (Temp[i][C - 1]) Temp[i][C - 1]--;
    }
    for (int i = 1; i < C - 1; i++) {
        if (Temp[0][i]) Temp[0][i]--;
        if (Temp[R - 1][i]) Temp[R - 1][i]--;
    }

    pair<int,int> corners[4] = {{ 0, 0 }, { R - 1, 0 }, { 0, C - 1 }, { R - 1, C - 1 }};
    for (auto [x, y] : corners) {
        if (Temp[x][y]) Temp[x][y]--;
    }
}

bool check() {
    for (auto [x, y] : P) {
        if (Temp[x][y] < K) {
            return false;
        }
    }
    
    return true;
}

int main() {
    FastIO
    input();
    init();

    int ans = 0;
    while (true) {
        heat();
        diffuse();
        cool();
        ans++;
        if (check() || ans > 100) break;
    }

    cout << ans << '\n';   
    return 0;
}
