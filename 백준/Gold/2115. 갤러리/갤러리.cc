#include <bits/stdc++.h>
#define R_MAX 1000
#define C_MAX 1000
using namespace std;

int R, C;
char gallery[R_MAX][C_MAX];
int isWall[R_MAX][C_MAX][4] = {0,};
bool occupied[R_MAX][C_MAX][4] = {false,};
int dr[4] = { -1, +1, 0, 0 };
int dc[4] = { 0, 0, -1, +1 };
int answer = 0;
// enum { UP, DOWN, LEFT, RIGHT };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> gallery[i][j];
        }
    }

    for (int i = 1; i < R-1; i++) {
        for (int j = 1; j < C-1; j++) {
            if (gallery[i][j] == 'X') continue;
            for (int dir = 0; dir < 4; dir++) {
                if (gallery[i + dr[dir]][j + dc[dir]] == 'X') {
                    isWall[i][j][dir]++;
                }
            }
        }
    }

    for (int i = 1; i < R-1; i++) {
        for (int j = 1; j < C-1; j++) {
            if (gallery[i][j] == 'X') continue;
            for (int wallDir = 0; wallDir < 4; wallDir++) {
                if (!isWall[i][j][wallDir]) continue;
                if (occupied[i][j][wallDir]) continue;

                for (int dir = 0; dir < 4; dir++) {
                    int r = i + dr[dir];
                    int c = j + dc[dir];
                    if (gallery[r][c] == 'X') continue;
                    if (!isWall[r][c][wallDir]) continue;
                    if (occupied[r][c][wallDir]) continue;

                    occupied[i][j][wallDir] = true;
                    occupied[r][c][wallDir] = true;
                    
                    answer++;
                }
            }
        }
    }

    cout << answer << '\n';
    
    return 0;
}
