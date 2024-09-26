#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int64 __f(int64 n, int k) {
    int64 two = 1LL << k;
    n /= two;
    int64 cnt = (n + 1) / 2;
    return cnt * two;
}

int64 f(int64 n) {
    int K = 0;
    for (int64 x = n; x > 0; x >>= 1) { K++; }

    int64 res = 0;
    for (int k = 0; k < K; k++) { res += __f(n, k); }

    return res;
}

int main() {
    int64 A, B; cin >> A >> B;
    cout << f(B) - f(A-1) << '\n';
    return 0;
}
