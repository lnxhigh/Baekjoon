#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;
enum Color { RED, PINK, ORANGE, BLUE, PURPLE };

int R, C;
int Maze[MAX][MAX];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };
bool visited[MAX][MAX][4][2];

void input() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> Maze[i][j];
        }
    }
}

int solve() {
    queue<tuple<int,int,int,bool,int>> q;
    q.push({ 0, 0, 0, false, 0 });
    visited[0][0][0][0] = true;

    while (!q.empty()) {
        auto [x, y, dir, flag, cnt] = q.front();
        q.pop();

        if (x == R - 1 && y == C - 1) return cnt;

        if (Maze[x][y] == PURPLE) {
            bool impassible = false;
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) impassible = true;
            else if (Maze[nx][ny] == RED || Maze[nx][ny] == BLUE) impassible = true;

            if (!impassible) {
                if (!visited[nx][ny][dir][0]) {
                    q.push({ nx, ny, dir, 0, cnt + 1 });
                    visited[nx][ny][dir][0] = true;
                }
                continue;
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

            if (Maze[nx][ny] == RED) continue;
            else if (Maze[nx][ny] == BLUE && !flag) continue;

            bool newFlag = flag;
            if (Maze[nx][ny] == ORANGE) newFlag = true;
            else if (Maze[nx][ny] == PURPLE) newFlag = false;
            
            if (visited[nx][ny][i][newFlag]) continue;

            q.push({ nx, ny, i, newFlag, cnt + 1 });
            visited[nx][ny][i][newFlag] = true;
        }
    }

    return -1;
}

int main() {
    FastIO
    input();
    cout << solve() << '\n';
    return 0;
}
