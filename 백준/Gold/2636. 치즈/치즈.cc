#include <bits/stdc++.h>
using namespace std;

int R, C;
const int MAX = 1 << 7;
bool cheese[MAX][MAX];
bool isAir[MAX][MAX];
bool visited[MAX][MAX];
bool canMelt[MAX][MAX];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

void initialize() {
    fill(&visited[0][0], &visited[R-1][C-1]+1, false);
    fill(&isAir[0][0], &isAir[R-1][C-1]+1, false);
    fill(&canMelt[0][0], &canMelt[R-1][C-1]+1, false);
}

void melt(bool cheese[MAX][MAX]) {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (!cheese[r][c]) continue; 

            int cnt = 0;
            for (int i = 0; i < 4; i++) {
                int nx = r + dx[i], ny = c + dy[i];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (isAir[nx][ny]) cnt++;
            }
            
            if (cnt > 0) canMelt[r][c] = true;
        }
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (canMelt[r][c]) cheese[r][c] = false;
        }
    }
}

int countCheese(bool cheese[MAX][MAX]) {
    int res = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (cheese[r][c]) res++;
        }
    }

    return res;
}

void updateAir(int x, int y) {
    visited[x][y] = true;
    if (!cheese[x][y]) isAir[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if (visited[nx][ny] || cheese[x][y]) continue;
        updateAir(nx, ny);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> cheese[r][c];
        }
    }

    int timeToMelt = 0;
    int lastCheeseCount = 0;

    while (true) {
        int cnt = countCheese(cheese);
        if (cnt <= 0) break;

        timeToMelt++;
        lastCheeseCount = cnt;

        initialize();
        updateAir(0, 0);
        melt(cheese);
    }

    cout << timeToMelt << '\n';
    cout << lastCheeseCount << '\n';
    return 0;
}
