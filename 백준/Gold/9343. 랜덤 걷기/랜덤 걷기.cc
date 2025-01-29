#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = unsigned long long;
const int MAX = 1 << 21;
const int64 MOD = 1'000'000'007;
int64 D[MAX];

int64 f(int64 x) {
    int64 y = 1;
    for (int64 p = MOD - 2; p; p >>= 1) {
        y = p & 1 ? y * x % MOD : y;
        x = x * x % MOD;
    }
    return y;
}

int main() {
    D[0] = 1;
    for (int64 i = 1; i < MAX; i++) {
        D[i] = (D[i - 1] * i) % MOD;
    }
    
    FastIO
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        int64 x = D[N << 1];
        int64 y = D[N] * D[N + 1] % MOD;
        
        int64 ans = x * f(y) % MOD;
        cout << ans << '\n';
    }
    
    return 0;
}
