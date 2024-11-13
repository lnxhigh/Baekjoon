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

void dfs(int depth, int cnt) {
    if (depth == cnt) {
        if (check()) {
            finish = true;
            ans = min(ans, cnt);
        }
        return;
    }

    for (int k = 1; k < N; k++) {
        if (finish) return;

        for (int i = 1; i <= H; i++) {
            if (finish) return;

            // 가로선을 놓을 수 있는지 검사한다
            if (X[i][k - 1] || X[i][k] || X[i][k + 1]) continue;

            X[i][k] = true;
            dfs(depth + 1, cnt);
            X[i][k] = false;
            
            // 이 부분 넣게 되면 커버하지 못하는 부분이 생기는듯 ...
            // (x, y) 에서 시작하는 것이 아닌
            // 전체탐색으로 바꾸면 같은 위상을 만들어낼 수 있지 않을까

            while (i <= H) {
                if (X[i][k - 1] || X[i][k + 1]) break;
                i++;
            }
        }
    }
}

int main() {
    cin >> N >> M >> H;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        X[a][b] = true;
    }

    for (int i = 0; i < 4; i++) dfs(0, i);
    if (ans >= 4) ans = -1;
    cout << ans << '\n';
    return 0;
}
