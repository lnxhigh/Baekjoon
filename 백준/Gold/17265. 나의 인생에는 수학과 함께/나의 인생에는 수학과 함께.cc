#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 20;

char Map[5][5];
int dx[3] = { -2, -1, 0 };
int dy[3] = { 0, -1, -2 };

int f(int x, int y, char op) {
    if (op == '+') return x + y;
    else if (op == '-') return x - y;
    else if (op == '*') return x * y;
    return 0;
}

int dfs(int x, int y, bool flag) {
    int k = Map[x][y] - '0';
    if (x == 0 && y == 0) return k;

    int ret = flag ? -INF : INF;
    for (int i = 0; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0) continue;

        int value = dfs(nx, ny, flag);

        if (dx[i] == -1 && dy[i] == -1) {
            int first  = f(value, k, Map[x - 1][y]);
            int second = f(value, k, Map[x][y - 1]);
            ret = flag ? max(ret, max(first, second)) : min(ret, min(first, second));
        }
        else {
            int tmp = f(value, k, Map[(x + nx)/2][(y + ny)/2]);
            ret = flag ? max(ret, tmp) : min(ret, tmp);
        }
    }

    return ret;
}

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Map[i][j];
        }
    }

    cout << dfs(N - 1, N - 1, true)  << ' ';
    cout << dfs(N - 1, N - 1, false) << '\n';
    return 0;
}
