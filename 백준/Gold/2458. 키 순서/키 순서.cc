#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 9;

int N, M;
bool D[MAX][MAX];

int main() {
    FastIO
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        D[i][i] = true;
    }

    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        D[x][y] = true;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                D[i][j] |= D[i][k] && D[k][j];
            }
        }
    }

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        bool flag = true;
        
        for (int k = 0; k < N; k++) {
            if (!D[i][k] && !D[k][i]) {
                flag = false;
                break;
            }
        }

        if (flag) cnt++;
    }

    cout << cnt << '\n';
    return 0;
}
