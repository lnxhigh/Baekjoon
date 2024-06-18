#include <bits/stdc++.h>
using namespace std;

int R, C;
int X, Y, D;
const int MAX = 50;

int Map[MAX][MAX];
bool visited[MAX][MAX];

enum SPACE { EMPTY, WALL };
enum DIR { NORTH, EAST, SOUTH, WEST };

int moveX[4] = { -1, 0, +1, 0 };
int moveY[4] = { 0, +1, 0, -1 };

bool finish;
int answer = 0;

int rotate(int d) {
    if      (d == DIR::NORTH) return DIR::WEST;
    else if (d == DIR::WEST ) return DIR::SOUTH;
    else if (d == DIR::SOUTH) return DIR::EAST;
    else if (d == DIR::EAST ) return DIR::NORTH;
    
    return -1;
}

void dfs(int x, int y, int d) {
    if (finish) return;

    if (!visited[x][y]) answer++;
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        d = rotate(d);
        int nextX = x + moveX[d], nextY = y + moveY[d];
        
        if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C) continue;
        else if (visited[nextX][nextY]) continue;
        else if (Map[nextX][nextY] == SPACE::WALL) continue;

        dfs(nextX, nextY, d);
    }

    int opposite = rotate(rotate(d));
    int nextX = x + moveX[opposite], nextY = y + moveY[opposite];
    if (Map[nextX][nextY] == SPACE::WALL) {
        finish = true;
        return;
    }

    dfs(nextX, nextY, d);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    cin >> X >> Y >> D;
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> Map[i][j];
        }
    }

    dfs(X, Y, D);
    cout << answer << '\n';

    return 0;
}
