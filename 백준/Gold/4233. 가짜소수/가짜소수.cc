#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;

int64 power(int64 x, int64 p, int64 mod) {
    int64 res = 1, mul = x;
    while (p) {
        if (p & 1) res = (res * mul) % mod;
        mul = (mul * mul) % mod;
        p >>= 1;
    }

    return res;
}

bool isPrime(int64 p) {
    for (int64 i = 2; i * i <= p; i++) {
        if (p % i == 0) return false;
    }
    return true;
}

bool solve(int64 x, int64 p) {
    if (isPrime(p)) return false;
    return power(x, p, p) == x;
}

int main() {
    FastIO
    
    while (true) {
        int64 p, x; cin >> p >> x;
        if (p == 0 && x == 0) break;

        string res = solve(x, p) ? "yes" : "no";
        cout << res << '\n';
    }

    return 0;
}
