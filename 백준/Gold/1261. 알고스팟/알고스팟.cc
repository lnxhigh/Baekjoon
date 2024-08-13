#include <bits/stdc++.h>
using namespace std;

int R, C;
const int MAX = 1 << 7;
bool maze[MAX][MAX];
bool visited[MAX][MAX];

int res = 0;
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

void Initialize() {
    fill(&visited[0][0], &visited[R-1][C-1], false);
}

void Explore(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if (visited[nx][ny] || maze[nx][ny]) continue;
        Explore(nx, ny);
    }
}

bool CanReach() {
    return visited[R-1][C-1];
}

void Destroy() {
    vector<pair<int,int>> xy;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (!visited[r][c] || maze[r][c]) continue;

            int cnt = 0;
            for (int i = 0; i < 4; i++) {
                int nx = r + dx[i], ny = c + dy[i];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (maze[nx][ny]) cnt++;
            }

            if (cnt > 0) { xy.push_back({ r, c }); }
        }
    }
    
    for (pair<int,int> p : xy) {
        int r = p.first, c = p.second;
        for (int i = 0; i < 4; i++) {
            int nx = r + dx[i], ny = c + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            maze[nx][ny] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> C >> R;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            char x;
            cin >> x;
            maze[r][c] = (x == '1');
        }
    }

    while (true) {
        Initialize();
        Explore(0, 0);
        if (CanReach()) break;

        res++;
        Destroy();
    }

    cout << res << '\n';
    return 0;
}
