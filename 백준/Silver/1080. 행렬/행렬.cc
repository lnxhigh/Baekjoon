#include <bits/stdc++.h>
#define MAX 50
using namespace std;

int R, C;
char A[2][MAX][MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> A[k][i][j];
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < R-2; i++) {
        for (int j = 0; j < C-2; j++) {
            if (A[0][i][j] == A[1][i][j]) continue;

            answer++;
            for (int nextI : { i, i+1, i+2 }) {
                for (int nextJ : { j, j+1, j+2 }) {
                    char &c = A[0][nextI][nextJ];
                    c = (c == '0') ? '1' : '0';
                }
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (A[0][i][j] != A[1][i][j]) answer = -1;
        }
    }

    cout << answer << '\n';
    
    return 0;

}