#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int R, C;
bool A[MAX][MAX];

int D[MAX << 2];
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, +1, 0, -1 };

bool inside(int x, int y) {
    return x > 0 && x <= R && y > 0 && y <= C;
}

int hole(int x, int y) {
    if (inside(x, y)) return 0;
    if (x == 0 && y == 0) return 0;
    else if (x == 0 && y == C + 1) return 0;
    else if (x == R + 1 && y == 0) return 0;
    else if (x == R + 1 && y == C + 1) return 0;

    if (y == 0) return x;
    else if (x == R + 1) return R + y;
    else if (y == C + 1) return (R + C) + (R - x + 1);
    else if (x == 0) return (R + C + R) + (C - y + 1);
    return 0;
}

int raycast(int x, int y) {
    int dir = -1;
    if (x == 0) dir = 2;
    else if (x == R + 1) dir = 0;
    else if (y == 0) dir = 1;
    else if (y == C + 1) dir = 3;
    assert(dir != -1);

    x += dx[dir], y += dy[dir];
    assert(inside(x, y));

    while (inside(x, y)) {
        if (A[x][y]) dir ^= 1;
        x += dx[dir], y += dy[dir];
    }

    return hole(x, y);
}

int main() {
    FastIO
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> A[i][j];
        }
    }

    for (int x = 0; x <= R + 1; x++) {
        for (int y = 0; y <= C + 1; y++) {
            int idx = hole(x, y);
            if (idx == 0) continue;
            D[idx] = raycast(x, y);
        }
    }

    for (int i = 1; i <= (R + C) * 2; i++) {
        cout << D[i] << ' ';
    }

    return 0;
}
