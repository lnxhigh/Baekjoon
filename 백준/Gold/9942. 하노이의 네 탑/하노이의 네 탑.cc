#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

long long N;

long long power(long long x, long long p) {
    if (p == 0) return 1;
    long long a = power(x, p / 2);
    a *= a;
    return (p % 2 == 0) ? a : (a * x);
}

long long T(long long n, long long r) {
    if (n == 1) return 1;
    if (r == 3) return power(2, n) - 1;
    long long k = n - round(sqrt(2*n+1)) + 1;
    return 2 * T(k, r) + T(n - k, r - 1);
}

int main() {
    FastIO
    long long TC = 0, N = 0;
    while (cin >> N) {
        cout << "Case " << ++TC << ": " << T(N, 4) << '\n';
    }
    return 0;
}
