#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int64 P = 97, Q = 1031;

int64 power(int64 x, int64 p, int64 mod) {
    int64 res = 1;
    while (p) {
        if (p & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        p >>= 1;
    }
    return res;
}

int64 choose(int64 n, int64 k, int64 mod) {
    if (n < k) return 0;
    k = min(k, n - k);
    
    int64 res = 1, mul = 1;
    for (int64 i = 0; i < k; i++) {
        res = res * (n - i) % mod;
        mul = mul * (i + 1) % mod;
    }
    
    int64 inv = power(mul, mod - 2, mod);
    return (res * inv) % mod;
}

int64 lucas(int64 N, int64 K, int64 p) {
    int64 res = 1;
    while (N || K) {
        res = res * choose(N % p, K % p, p) % p; 
        N /= p; K /= p;
    }
    return res;
}

tuple<int64,int64,int64> euclidean(int64 a, int64 b) {
    if (b == 0) return { a, 1, 0 };
    auto [ g, x, y ] = euclidean(b, a % b);
    return { g, y, x - (a / b) * y };
}

int64 solve(int64 N, int64 K) {
    if (K == 0) return N ? 0 : 1;
    int64 M = P * Q;

    int64 res = 0;
    for (int64 i : { P, Q }) {
        int64 Mi = M / i;
        auto [ g, yi, _ ] = euclidean(Mi, i);
        yi = (yi % i + i) % i;
        int64 ri = lucas(N - 1, K - 1, i); 
        
        res += Mi * yi * ri;
    }

    return res % M;
}

int main() {
    FastIO

    int T; cin >> T;
    while (T--) {
        int64 N, M; cin >> N >> M; 
        M--; // last element is zero
        
        // The answer is M H M-N = N-1 C M-1
        cout << solve(N, M) << '\n';
    }

    return 0;
}
