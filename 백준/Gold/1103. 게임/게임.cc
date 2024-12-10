#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 6;

int R, C;
int A[MAX][MAX];
int D[MAX][MAX];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

bool cycle;
enum Color { WHITE, GRAY, BLACK };
Color V[MAX][MAX];

void input() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char c; cin >> c;
            if (c == 'H') c = '0';

            int x = (c - '0');
            A[i][j] = x;
        }
    }
}

bool inside(int x, int y) {
    if (x < 0 || x >= R || y < 0 || y >= C) return false;
    return true;
}

int dfs(int x, int y) {
    if (cycle) return D[x][y] = 0;
    else if (D[x][y] != -1) return D[x][y];

    V[x][y] = Color::GRAY;
    int cnt = 0;

    for (int i = 0; i < 4; i++) {
        int nx = x + A[x][y] * dx[i], ny = y + A[x][y] * dy[i];
        if (!inside(nx, ny) || A[nx][ny] == 0) continue;
        
        if (V[nx][ny] == Color::WHITE) { 
            cnt = max(cnt, dfs(nx, ny)); 
        }
        else if (V[nx][ny] == Color::GRAY ) { 
            cycle = true; break; 
        }
        else if (V[nx][ny] == Color::BLACK) { 
            cnt = max(cnt, D[nx][ny]); 
        }
    }

    V[x][y] = Color::BLACK;
    return D[x][y] = ++cnt;
}

int main() {
    FastIO
    memset(D, -1, sizeof(D));

    input();
    int ans = dfs(0, 0);
    if (cycle) ans = -1;
    cout << ans << '\n';
    return 0;
}
