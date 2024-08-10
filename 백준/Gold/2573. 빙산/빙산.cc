#include <bits/stdc++.h>
using namespace std;

int R, C;
const int MAX = 300;
int H[MAX][MAX];
int A[MAX][MAX];

int dx[4] = { 0, 0, -1, +1 };
int dy[4] = { -1, +1, 0, 0 };
bool visited[MAX][MAX];

void melt() {
    fill(&A[0][0], &A[R-1][C-1], 0);

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (H[r][c] == 0) continue;

            int cnt = 0;
            for (int i = 0; i < 4; i++) {
                int nextX = r + dx[i];
                int nextY = c + dy[i];
                if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C) continue;
                if (H[nextX][nextY] == 0) cnt++;
            }

            A[r][c] = cnt;
        }
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            H[r][c] -= A[r][c];
            if (H[r][c] < 0) H[r][c] = 0;
        }
    }
}

bool hasMelted() {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (H[r][c] != 0) return false;
        }
    }
    return true;
}

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C) continue;
        if (visited[nextX][nextY] || H[nextX][nextY] == 0) continue;
        dfs(nextX, nextY);
    }
}

int countIcebergs() {
    fill(&visited[0][0], &visited[R-1][C-1] + 1, false);

    int res = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (H[r][c] == 0 || visited[r][c]) continue;
            dfs(r, c);
            res++;
        }
    }
    return res;
}

int main() {
    cin >> R >> C;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> H[r][c];
        }
    }

    int res = 0;
    bool isAllMelted = false;

    while (true) {
        isAllMelted = hasMelted();
        if (isAllMelted) break;
        
        res++;
        melt();
        int numIcebergs = countIcebergs();
        if (numIcebergs >= 2) break;
    }

    if (isAllMelted) res = 0;
    cout << res << '\n';
    return 0;
}
