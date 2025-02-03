#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int64 MOD = 1'000'000'007;

int64 f(int64 x, int64 p) {
    int64 y = 1;
    while (p) {
        if (p & 1) y = y * x % MOD;
        x = x * x % MOD;
        p >>= 1;
    }
    return y;
}

int main() {
    FastIO
    int T; cin >> T;
    
    while (T--) {
        int64 p; cin >> p;
        int64 C, N; cin >> C >> N;

        vector<int64> D(N + 1);
        D[0] = 1;

        int64 t = 0;
        int64 F = f((MOD + 1 - p) % MOD, C - 1);

        for (int64 k = 1; k <= N; k++) {
            int64 x = (k >= C) ? D[k - C] * F % MOD: 0;
            D[k] = x + (MOD + 1 - x) * p % MOD;
            D[k] %= MOD;

            t = D[k] * (t + 1) % MOD + (MOD + 1 - D[k]) * t % MOD;
            t %= MOD;
            cout << t << '\n';
        }
    }

    return 0;
}
