#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 200;

int n, k, m;
int mat[MAX][MAX];
int tmp[MAX][MAX];
int mul[MAX][MAX];

int main() {
    FastIO

    cin >> n >> k >> m;

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y; --x, --y;
        mat[i][i] = 1;
        mul[i][x] = mul[i][y] = 1;
    }

    while (k) {

        // update matrix

        if (k & 1) {
            memset(tmp, 0, sizeof(tmp));

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int t = 0; t < n; t++) {
                        tmp[i][j] += mat[i][t] *  mul[t][j];
                    }
                    if (tmp[i][j]) tmp[i][j] = 1;
                }
            }

            memcpy(mat, tmp, sizeof(mat));
        }

        // update multiplier

        memset(tmp, 0, sizeof(tmp));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int t = 0; t < n; t++) {
                    tmp[i][j] += mul[i][t] *  mul[t][j];
                }
                if (tmp[i][j]) tmp[i][j] = 1;
            }
        }

        memcpy(mul, tmp, sizeof(mul));

        // update k

        k >>= 1;
    }
    
    while (m--) {
        int a, b; cin >> a >> b; --a, --b;
        string ans = (mat[a][b] > 0) ? "death" : "life";
        cout << ans << '\n';
    }
    
    return 0;
}
