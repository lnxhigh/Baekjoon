#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

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

int main() {
    int64 N, K, P;
    cin >> N >> K >> P;
    
    int64 res = 1;
    while (N && K) {
        res = res * choose(N % P, K % P, P) % P; 
        N /= P; K /= P;
    }

    cout << res << '\n';
    return 0;
}
