#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

int main() {
    FastIO

    int tc = 0;
    while (++tc) {
        int R, C; cin >> R >> C;
        if (R == 0 && C == 0) break;

        int x, y;
        vector<string> A(R);
        vector<vector<bool>> D(R, vector<bool>(C));

        for (int i = 0; i < R; i++) {
            cin >> A[i];

            for (int j = 0; j < C; j++) {
                char &c = A[i][j];
                D[i][j] = (c == '+') || (c == 'W') || (c == 'B');
                if (c == 'w' || c == 'W') x = i, y = j;

                if (c == '+' || c == 'w' || c == 'W') c = '.';
                else if (c == 'B') c = 'b';
            }
        }

        string keys; cin >> keys;
        bool complete = false;

        for (char key : keys) {
            int dir = -1;

            if (key == 'U') dir = 0;
            else if (key == 'D') dir = 2;
            else if (key == 'L') dir = 1;
            else if (key == 'R') dir = 3;

            assert(dir != -1);

            int nx = x + dx[dir];
            int ny = y + dy[dir];
            char c = A[nx][ny];
            
            if (c == '.') {
                x = nx, y = ny;
            }
            else if (c == 'b') {
                int tx = nx + dx[dir];
                int ty = ny + dy[dir];
                char nc = A[tx][ty];

                if (nc == '.') {
                    A[tx][ty] = 'b';
                    A[nx][ny] = '.';
                    x = nx, y = ny;
                }
            }

            bool chk = true;
            
            for (int i = 0; i < R && chk; i++) {
                for (int j = 0; j < C && chk; j++) {
                    if (D[i][j] && A[i][j] != 'b') chk = false;
                }
            }
            
            if (chk) {
                complete = true;
                break;
            }
        }

        A[x][y] = 'w';
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (!D[i][j]) continue;

                if (A[i][j] == 'b') A[i][j] = 'B';
                else if (A[i][j] == 'w') A[i][j] = 'W';
                else A[i][j] = '+';
            }
        }

        string result = (complete) ? "complete" : "incomplete";
        cout << "Game " << tc << ": " << result << '\n';

        for (int i = 0; i < R; i++) {
            cout << A[i] << '\n';
        }
    }

    return 0;
}
