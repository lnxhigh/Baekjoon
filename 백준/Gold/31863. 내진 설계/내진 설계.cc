#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int R, C;
char A[MAX][MAX];

int X, Y;
int total = 0;
short int D[MAX][MAX];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

void input() {
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char x; cin >> x;
            A[i][j] = x;

            if (x == '@') {
                X = i, Y = j;
            }
            else if (x == '*' || x == '#') {
                total++;
                if (x == '*') D[i][j] = 1;
                else if (x == '#') D[i][j] = 2;
            }
        }
    }
}

int solve(int x, int y) {
    int cnt = 0;
    queue<pair<int,int>> q;

    // 본진
    for (int i = 0; i < 4; i++) {
        int cx = x, cy = y;
        for (int j = 0; j < 2; j++) {
            cx += dx[i], cy += dy[i];
            
            if (cx < 0 || cx >= R || cy < 0 || cy >= C) break;
            else if (A[cx][cy] == '|') break;
            
            if (A[cx][cy] == '*' || A[cx][cy] == '#') {
                --D[cx][cy];
                if (D[cx][cy] == 0) q.push({ cx, cy });
            }
        }
    }

    // 여진
    while (!q.empty()) {
        cnt++;
        auto [cx, cy] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            else if (D[nx][ny] == 0) continue;

            --D[nx][ny];
            if (D[nx][ny] == 0) q.push({ nx, ny });
        }
    }

    return cnt;
}

int main() {
    FastIO
    input();
    int cnt = solve(X, Y);
    cout << cnt << ' ' << total - cnt << '\n';
    return 0;
}
