#include <iostream>
#define N_MAX 16
using namespace std;

int N;
int house[N_MAX][N_MAX];

int dp[3][16][16] = {0,};
enum { HORIZONTAL, VERTICAL, DIAGONAL };
enum { FREE, WALL };
int answer = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> house[r][c];
        }
    }

    dp[HORIZONTAL][0][1] = 1;
    
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {

            // Horizontal
            if (c+1 < N and house[r][c+1] != WALL) {
                dp[HORIZONTAL][r][c+1] += dp[HORIZONTAL][r][c];
                dp[HORIZONTAL][r][c+1] += dp[DIAGONAL][r][c];
            }

            // Vertical
            if (r+1 < N and house[r+1][c] != WALL) {
                dp[VERTICAL][r+1][c] += dp[VERTICAL][r][c];
                dp[VERTICAL][r+1][c] += dp[DIAGONAL][r][c];
            }

            // Diagonal
            if (r+1 < N and c+1 < N) {
                if (house[r+1][c+1] != WALL and house[r][c+1] != WALL and house[r+1][c] != WALL) {
                    dp[DIAGONAL][r+1][c+1] += dp[HORIZONTAL][r][c];
                    dp[DIAGONAL][r+1][c+1] += dp[VERTICAL][r][c];
                    dp[DIAGONAL][r+1][c+1] += dp[DIAGONAL][r][c];
                }
            }
        }
    }

    for (int direction : { HORIZONTAL, VERTICAL, DIAGONAL }) {
        answer += dp[direction][N-1][N-1];
    }

    cout << answer << '\n';
    return 0;
}