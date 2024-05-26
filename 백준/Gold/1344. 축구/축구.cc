#include <bits/stdc++.h>
using namespace std;

int A, B;

int choose(int n, int k) {
    int res = 1;
    k = min(k, n - k);
    for (int i = 0; i < n-k; i++) {
        res *= n - i;
        res /= i + 1;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> A >> B;
    double p = 1.0 * A / 100.0;
    double q = 1.0 * B / 100.0;
    
    int total = 18;
    set<int> primes = { 2, 3, 5, 7, 11, 13, 17 };

    double pp = 0.0, qq = 0.0;
    for (int prime : primes) {
        pp += choose(total, prime) * pow(p, prime) * pow(1-p, total - prime);
        qq += choose(total, prime) * pow(q, prime) * pow(1-q, total - prime);
    }

    double res = 1.0 - (1.0 - pp) * (1.0 - qq);

    cout << res << '\n';
    
    return 0;
}
