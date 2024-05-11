#include <bits/stdc++.h>
using namespace std;

int R, C, K;
char letter;
int board[2001][2001];
int sum[2001][2001] = {0,};
int answer = (1 << 30);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> R >> C >> K;
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> letter;
            if      (letter == 'B') board[r][c] = 0;
            else if (letter == 'W') board[r][c] = 1;
            board[r][c] ^= ((r+c) & 1);
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            sum[r][c] = sum[r-1][c] + sum[r][c-1] - sum[r-1][c-1] + board[r][c];
        }
    }

    for (int r = 1; r <= R - K + 1; r++) {
        for (int c = 1; c <= C - K + 1; c++) {
            int value = sum[r+K-1][c+K-1] - sum[r+K-1][c-1] - sum[r-1][c+K-1] + sum[r-1][c-1];
            answer = min({answer, value, K*K-value});
        }
    }

    cout << answer << '\n';

    return 0;
}
