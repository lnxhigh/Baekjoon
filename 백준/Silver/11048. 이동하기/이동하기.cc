#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

const int MAX = 1 << 10;
int A[MAX][MAX], D[MAX][MAX];

int main() {
    FastIO
    int R, C; cin >> R >> C;
    
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> A[r][c];
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            D[r][c] = max({ D[r-1][c], D[r][c-1], D[r-1][c-1] });
            D[r][c] += A[r][c];
        }
    }

    cout << D[R][C] << '\n';
    return 0;
}
