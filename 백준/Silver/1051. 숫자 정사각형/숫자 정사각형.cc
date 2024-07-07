#include <bits/stdc++.h>
using namespace std;

int R, C;
const int MAX = 50;
int A[MAX][MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char c;
            cin >> c;
            int k = c - '0';
            A[i][j] = k;
        }
    }

    int maxLen = min(R, C);
    int res = 0;

    for (int len = 0; len < maxLen; len++) {
        for (int i = 0; i < R - len; i++) {
            for (int j = 0; j < C - len; j++) {
                if (A[i][j] == A[i + len][j + len]) {
                    int x[4] = { i, i, i + len, i + len};
                    int y[4] = { j, j + len, j + len, j };

                    int check = true;
                    for (int i = 0; i < 3; i++) {
                        if (A[x[i]][y[i]] != A[x[i+1]][y[i+1]]) check = false;
                    }
                    
                    if (check) res = max(res, len + 1);
                }
            }
        }
    }
    
    cout << res * res << '\n';
    return 0;
}
