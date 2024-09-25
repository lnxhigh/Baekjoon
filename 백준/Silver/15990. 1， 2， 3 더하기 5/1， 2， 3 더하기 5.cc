#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

const int MOD = 1e+9 + 9;
const int MAX = 100001;
int D[MAX][4];

int main() {
    FastIO
    int T; cin >> T;

    D[0][1] = D[1][1] = D[2][2] = 1;

    for (int i = 3; i < MAX; i++) {
        D[i][1] = (D[i-1][2] + D[i-1][3]) % MOD;
        D[i][2] = (D[i-2][3] + D[i-2][1]) % MOD;
        D[i][3] = (D[i-3][1] + D[i-3][2]) % MOD;
    }

    while (T--) {
        int N; cin >> N;
        int res = D[N][1] + D[N][2];
        res %= MOD; res += D[N][3]; res %= MOD;

        cout << res << '\n';
    }

    return 0;
}
