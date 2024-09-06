#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll A, B;

int main() {
    cin >> A >> B;

    const int M = sqrt(B);
    const int MAX = M + 1;
    vector<bool> isPrime(MAX, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 0; i < MAX; i++) {
        if (!isPrime[i]) continue;
        for (int j = i + i; j < MAX; j += i) {
            isPrime[j] = false;
        }
    }

    vector<long long> primes;
    for (int i = 0; i < MAX; i++) {
        if (isPrime[i]) primes.push_back((ll) i);
    }

    int res = 0;
    for (const long long &p : primes) {
        long long q = p * p;
        while (q <= B) {
            if (q >= A) res++;
            if (p > 100000) break;
            q *= p;
        }
    }

    cout << res << '\n';
    return 0;
}
