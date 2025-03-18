#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int INF = 1 << 20;

bool A[10][10];
int D[6] = { 0, 5, 5, 5, 5, 5 };
int ans = INF;

bool f(int x, int y, int len) {
    if (D[len] == 0 || x + len > 10 || y + len > 10) {
        return false;
    }

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (!A[x + i][y + j]) {
                return false;
            }
        }
    }

    return true;
}

void cover(int x, int y, int len, bool flag) {
    if (!flag) D[len]--;
    else D[len]++;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            A[x + i][y + j] = flag;
        }
    }
}

void dfs(int x, int y, int depth) {
    if (x == 10 || y == 10) {
        if (x == 10) ans = min(ans, depth);
        else if (y == 10) dfs(x + 1, 0, depth);
        return;
    }

    if (depth >= ans) {
        return;
    }
    if (!A[x][y]) {
        dfs(x, y + 1, depth);
        return;
    }

    for (int len = 1; len <= 5; len++) {
        if (f(x, y, len)) {
            cover(x, y, len, false);
            dfs(x, y + 1, depth + 1);
            cover(x, y, len, true);
        }
    }
}

int main() {
    FastIO

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> A[i][j];
        }
    }

    dfs(0, 0, 0);
    if (ans >= INF) ans = -1;
    cout << ans << '\n';

    return 0;
}
