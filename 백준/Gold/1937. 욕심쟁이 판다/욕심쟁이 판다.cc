#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 500;

int Forest[N_MAX][N_MAX];
int D[N_MAX][N_MAX];

int dx[4] = { -1, +1, 0, 0 };
int dy[4] = { 0, 0, -1, +1 };

int f(int x, int y) {
    if (D[x][y] != -1) return D[x][y];

    int res = 0;
    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i], nextY = y + dy[i];
        if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) continue;

        if (Forest[nextX][nextY] > Forest[x][y]) {
            res = max(res, f(nextX, nextY) + 1);
        }
    }

    return D[x][y] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Forest[i][j];
        }
    }

    int res = 0;
    memset(D, -1, sizeof(D));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res = max(res, f(i, j));
        }
    }

    cout << res + 1 << '\n';
    return 0;
}
