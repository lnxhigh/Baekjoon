#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 9;
const int INF = 1 << 30;

int R, C;
char A[MAX][MAX];
int X, Y;

string dirstr = "URDL";
bool vis[MAX][MAX][4];
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, +1, 0, -1 };

bool isInside(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

int raycast(int x, int y, int dir) {
    int t = 0;
    memset(vis, false, sizeof(vis));
    
    while (isInside(x, y) && A[x][y] != 'C') {
        if (vis[x][y][dir]) return INF;
        vis[x][y][dir] = true;

        if (A[x][y] == '/') dir ^= 1;
        else if (A[x][y] == '\\') dir ^= 3;
        
        t++;
        x += dx[dir], y += dy[dir];
    }

    return t;
}

int main() {
    FastIO
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> A[i][j];
        }
    }
    cin >> X >> Y;
    --X, --Y;

    int dir = -1;
    int ans = -1;

    for (int i = 3; i >= 0; i--) {
        int t = raycast(X, Y, i);
        if (t >= ans) dir = i, ans = t; 
    }

    cout << dirstr[dir] << '\n';
    if (ans >= INF) cout << "Voyager" << '\n';
    else cout << ans << '\n';
    return 0;
}
