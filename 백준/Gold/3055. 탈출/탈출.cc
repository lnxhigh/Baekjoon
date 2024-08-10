#include <bits/stdc++.h>
using namespace std;
using xy = pair<int,int>;

int R, C;
const int MAX = 1 << 8;
char forest[MAX][MAX];

bool flooded[MAX][MAX];
bool visited[MAX][MAX];

queue<xy> painter, flood;
xy dest;

int dx[4] = { 0, 0, -1, +1 };
int dy[4] = { -1, +1, 0, 0 };

void updateFlood() {
    int len = flood.size();
    while (len--) {
        xy cur = flood.front();
        int curX = cur.first, curY = cur.second;
        flooded[curX][curY] = true;

        flood.pop();
        
        for (int i = 0; i < 4; i++) {
            int nextX = curX + dx[i], nextY = curY + dy[i];
            if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C) continue;
            if (flooded[nextX][nextY]) continue;
            flooded[nextX][nextY] = true;
            
            if (forest[nextX][nextY] == 'D' || forest[nextX][nextY] == 'X') continue;
            xy next = { nextX, nextY };
            flood.push(next);
        }
    }
}

void updatePainter() {
    int len = painter.size();
    while (len--) {
        xy cur = painter.front();
        int curX = cur.first, curY = cur.second;
        visited[curX][curY] = true;

        painter.pop();
        
        for (int i = 0; i < 4; i++) {
            int nextX = curX + dx[i], nextY = curY + dy[i];
            if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C) continue;
            if (visited[nextX][nextY]) continue;
            visited[nextX][nextY] = true;

            if (flooded[nextX][nextY]) continue;
            if (forest[nextX][nextY] == 'X') continue;

            xy next = { nextX, nextY };
            painter.push(next);
        }
    }
}

bool hasReached() {
    return visited[dest.first][dest.second];
}

int main() {
    cin >> R >> C;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> forest[r][c];
            if (forest[r][c] == '*') flood.push({ r, c });
            else if (forest[r][c] == 'S') painter.push({ r, c });
            else if (forest[r][c] == 'D') dest = { r, c };
        }
    }
    
    int res = 0;
    while (!flood.empty() || !painter.empty()) {
        updateFlood();
        updatePainter();

        res++;
        if (hasReached()) break;
    }

    if (hasReached()) cout << res << '\n';
    else cout << "KAKTUS" << '\n';
    return 0;
}
