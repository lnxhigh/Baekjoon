#include <bits/stdc++.h>
using namespace std;

int N;
const int MOD = 9901;

int power(int x, int p) {
    if (p == 0) return 1;
    int a = power(x, p / 2);
    a = (a * a) % MOD;
    return (p % 2 == 0) ? a : (a * x) % MOD;
}

int T(int n, int r) {
    if (n == 1) return 1;
    if (r == 3) return power(2, n) - 1;
    
    int k = n - round(sqrt(2*n+1)) + 1;
    return (2 * T(k, r) + T(n - k, r - 1)) % MOD;
}

int main() {
    cin >> N;
    cout << T(N, 4) << '\n';
    return 0;
}
