#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

enum Stone { NONE, BLACK, WHITE };
Stone Go[19][19];
bool vis[19][19];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

pair<Stone,int> bfs(int x, int y, int N) {
    int cnt = 0;
    bool white = false, black = false;

    queue<pair<int,int>> q;
    q.push({ x, y });
    vis[x][y] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        cnt++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            else if (vis[nx][ny]) continue;
            
            if (Go[nx][ny] != Stone::NONE) {
                if (Go[nx][ny] == Stone::BLACK) black = true;
                else if (Go[nx][ny] == Stone::WHITE) white = true;
            }
            else {
                q.push({ nx, ny });
                vis[nx][ny] = true;
            }
        }
    }

    if (black && white) return { Stone::NONE, 0 };
    
    Stone stone = black ? Stone::BLACK : Stone::WHITE;
    return { stone, cnt };
}

int main() {
    FastIO
    while (true) {
        int N; cin >> N;
        if (N == 0) break;

        int b, w; cin >> b >> w;
        memset(Go, 0, sizeof(Go));
        memset(vis, false, sizeof(vis));

        while (b--) {
            int x, y; cin >> x >> y; 
            --x, --y;
            Go[x][y] = Stone::BLACK;
        }

        while (w--) {
            int x, y; cin >> x >> y; 
            --x, --y;
            Go[x][y] = Stone::WHITE;
        }

        int black = 0, white = 0;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (Go[i][j] != Stone::NONE) continue;
                else if (vis[i][j]) continue;

                auto [color, cnt] = bfs(i, j, N);
                if (color == Stone::BLACK) black += cnt;
                else if (color == Stone::WHITE) white += cnt;
            }
        }

        if (black == white) {
            cout << "Draw" << '\n';
        }
        else {
            int diff = black - white;
            string winner = (diff > 0) ? "Black" : "White";
            cout << winner << " wins by " << abs(diff) << '\n';
        }
    }
    
    return 0;
}
