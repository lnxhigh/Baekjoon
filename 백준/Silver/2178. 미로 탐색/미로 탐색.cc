#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int R, C;
int maze[100][100];
int dist[100][100] = {0,};

void bfs(pair<int,int> start, int maze[100][100]) {
    int visited[100][100] = {0,};
    queue< pair< pair<int,int>, int > > q;
    
    q.push({start, 0});
    visited[start.X][start.Y]++;

    int dx[4] = {0, 0, -1, +1};
    int dy[4] = {-1, +1, 0, 0};

    while (not q.empty()) {
        pair<int,int> cur = q.front().X;
        int depth = q.front().Y;
        q.pop();

        dist[cur.X][cur.Y] = depth;

        for (int i = 0; i < 4; i++) {
            int x = cur.X + dx[i], y = cur.Y + dy[i];
            pair<int,int> next = {x, y};

            if (x < 0 || x >= R) continue;
            if (y < 0 || y >= C) continue;
            if (visited[x][y]++) continue;
            if (maze[x][y] == 0) continue;

            q.push({next, depth+1});
        }
    }

}

int main() {
    cin >> R >> C;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            char x;
            cin >> x;
            maze[r][c] = x - '0';
        }
    }

    bfs({0, 0}, maze);
    cout << dist[R-1][C-1] + 1 << "\n";
    
    return 0;
}