#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1e9 + 7;

int64 power(int64 x, int64 p) {
    int64 res = 1, mul = x;
    while (p) {
        if (p & 1) res = (res * mul) % MOD;
        mul = (mul * mul) % MOD;
        p >>= 1;
    }
    return res;
}

int main() {
    int64 N, M; cin >> N >> M;
    M = min(M, N - M);
    
    int64 res = 1, mul = 1;
    for (int64 i = 0; i < M; i++) {
        res = (res * (N - i)) % MOD;
        mul = (mul * (i + 1)) % MOD;
    }

    int64 inv = power(mul, MOD - 2);
    res = (res * inv) % MOD;
    cout << res << '\n';
    return 0;
}
