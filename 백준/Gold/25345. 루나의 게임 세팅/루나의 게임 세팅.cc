#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int64 MOD = 1000000007;

int64 power(int64 x, int64 p) {
    if (p == 0) return 1;

    int64 a = power(x, p / 2);
    a = (a * a) % MOD;
    return p & 1 ? (a * x) % MOD : a; 
}

int64 choose(int64 n, int64 k) {
    k = min(k, n - k);

    int64 res = 1, mul = 1;
    for (int64 i = 0; i < k; i++) {
        res *= n - i, mul *= i + 1;
        res %= MOD, mul %= MOD;
    }

    int64 inv = power(mul, MOD-2);
    res *= inv; res %= MOD;
    return res;
}

int main() {
    int64 N, K;
    cin >> N >> K;

    vector<int64> A(N);
    for (auto &x : A) cin >> x;
    
    int64 res = (choose(N, K) * power(2, K - 1)) % MOD;
    cout << res << '\n';

    return 0;
}
