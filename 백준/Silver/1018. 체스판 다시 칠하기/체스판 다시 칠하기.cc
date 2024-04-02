#include <bits/stdc++.h>
using namespace std;

int R, C;
char board[50][50];
int answer = 100;

int check(int x, int y) {
    int w = 0, b = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((x+i + y+j) & 1) {
                if (board[x+i][y+j] == 'B') b++;
                else if (board[x+i][y+j] == 'W') w++;
            }
            else {
                if (board[x+i][y+j] == 'B') w++;
                else if (board[x+i][y+j] == 'W') b++;
            }
        }
    }
    
    return min(b, w);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> R >> C;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> board[r][c];
        }
    }

    for (int x = 0; x <= R - 8; x++) {
        for (int y = 0; y <= C - 8; y++) {
            answer = min(answer, check(x, y));
        }
    }
    cout << answer << "\n";
    
    return 0;
}