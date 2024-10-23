#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int64 MOD = 1e9 + 7;

int64 power(int64 x, int64 p) {
    int64 y = 1;
    while (p) {
        if (p & 1) y = y * x % MOD;
        x = x * x % MOD;
        p >>= 1;
    }
    return y;
}

int64 solve(int64 L) {
    if (L & 1) return 0;

    int64 x = 1, y = 1;
    for (int64 i = 1; i <= L; i++) x = x * i % MOD;
    
    L >>= 1;
    for (int64 i = 1; i <= L; i++) y = y * i % MOD;
    y = y * y % MOD;
    y = y * (L + 1) % MOD;

    int64 inv = power(y, MOD - 2);
    return x * inv % MOD;
}

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int64 L; cin >> L;
        cout << solve(L) << '\n';
    }
    return 0;
}
