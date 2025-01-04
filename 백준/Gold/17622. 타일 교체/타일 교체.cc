#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 55;
const int INF = 1 << 20;

int N, K;
int A[MAX][MAX];

enum { UP, LEFT, DOWN, RIGHT };
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

tuple<int,int,int> move(int x, int y, int dir) {
    int nxt = -1;

    if (A[x][y] == 0) {
        if (dir == UP) nxt = RIGHT;
        else if (dir == LEFT) nxt = DOWN;
    }
    else if (A[x][y] == 1) {
        if (dir == RIGHT) nxt = DOWN;
        else if (dir == UP) nxt = LEFT;
    }
    else if (A[x][y] == 2) {
        if (dir == DOWN) nxt = RIGHT;
        else if (dir == LEFT) nxt = UP;
    }
    else if (A[x][y] == 3) {
        if (dir == RIGHT) nxt = UP;
        else if (dir == DOWN) nxt = LEFT;
    }
    else if (A[x][y] == 4) {
        if (dir == DOWN || dir == UP) nxt = dir;
    }
    else if (A[x][y] == 5) {
        if (dir == LEFT || dir == RIGHT) nxt = dir;
    }

    if (nxt == -1) return { -1, -1, -1 };
    return { x + dx[nxt], y + dy[nxt], nxt };
}

int f(int x, int y, int dir) {
    int cnt = 0;
    
    while (x >= 0 && x < N && y >= 0 && y < N) {
        cnt++;
        auto [nx, ny, nxtDir] = move(x, y, dir);
        if (nxtDir == -1) return INF;
        x = nx, y = ny, dir = nxtDir;
    }

    if (x != N - 1 || y != N || dir != RIGHT) return INF;
    return cnt;
}

int solve() {
    if (K == 0) {
        int cnt = f(0, 0, RIGHT);
        return cnt < INF ? cnt : -1;
    }

    int cnt = INF;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x = A[i][j];

            for (int k = 0; k < 6; k++) {
                if (k == x) continue;

                A[i][j] = k;
                cnt = min(cnt, f(0, 0, RIGHT));
            }

            A[i][j] = x;
        }
    }

    return cnt < INF ? cnt : -1;
}

void input() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
}

int main() {
    FastIO
    input();
    cout << solve() << '\n';
    return 0;
}
