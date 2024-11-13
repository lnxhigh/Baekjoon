#include <bits/stdc++.h>
using namespace std;

int N, M, H;
bool X[32][12];
bool finish = false;
int ans = 4;

bool check() {
    for (int k = 1; k <= N; k++) {
        int t = k;
        for (int i = 1; i <= H; i++) {
            if (X[i][t-1]) t--;
            else if (X[i][t]) t++;
        }
        if (t != k) return false;
    }

    return true;
}

void dfs(int x, int y, int depth, int cnt) {
    if (depth == cnt) {
        if (check()) {
            finish = true;
            ans = min(ans, cnt);
        }
        return;
    }

    // (x, y) 에서 탐색을 시작
    for (int k = y; k < N; k++) {
        if (finish) return;
        int s = (k == y) ? x : 0;

        for (int i = s; i <= H; i++) {
            if (finish) return;

            // 가로선을 놓을 수 있는지 검사한다
            if (X[i][k - 1] || X[i][k] || X[i][k + 1]) continue;

            X[i][k] = true;
            dfs(i + 1, k, depth + 1, cnt);
            X[i][k] = false;

            // 
            // while (i <= H) {
            //     if (X[i][k - 1] || X[i][k + 1]) break;
            //     i++;
            // }
        }
    }
}

int main() {
    cin >> N >> M >> H;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        X[a][b] = true;
    }

    for (int i = 0; i < 4; i++) dfs(1, 1, 0, i);
    if (ans >= 4) ans = -1;
    cout << ans << '\n';
    return 0;
}
