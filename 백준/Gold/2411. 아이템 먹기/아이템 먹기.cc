#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int R, C, I, O;
const int MAX = 1 << 7;
int A[MAX][MAX], D[MAX][MAX];

void update(const int &r, const int &c) {
    if (A[r][c] == -1) return;
    for (int k = c+1; k <= C; k++) {
        if (A[r-1][k] == 1) return;
    }
    for (int k = r+1; k <= R; k++) {
        if (A[k][c-1] == 1) return;
    }
    D[r][c] = D[r-1][c] + D[r][c-1];
}

int main() {
    FastIO
    cin >> R >> C >> I >> O;
    for (int i = 0; i < I; i++) {
        int x, y; cin >> x >> y;
        A[x][y] = 1;
    }
    for (int i = 0; i < O; i++) {
        int x, y; cin >> x >> y;
        A[x][y] = -1;
    }

    D[0][1] = 1;
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            update(r, c);
        }
    }

    cout << D[R][C] << '\n';
    return 0;
}
