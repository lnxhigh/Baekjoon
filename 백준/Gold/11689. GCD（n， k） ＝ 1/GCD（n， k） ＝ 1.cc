#include <bits/stdc++.h>
#define P_MAX 1000001
using namespace std;

bool isPrime[P_MAX];
vector<int> primes;

vector<long long> factorize(long long N) {
    vector<long long> res;
    for (int prime : primes) {
        if (N % prime == 0) {
            res.push_back(prime);
            while (N % prime == 0) N /= prime;
        }
    }
    if (N != 1) res.push_back(N);
    return res;
}

long long phi(long long N) {
    long long res = N;
    vector<long long> factors = factorize(N);
    for (long long factor : factors) {
        res -= res / factor;
    }
    return res;
}

int main() {
    long long N;
    cin >> N;
    int P = floor(sqrt(N)) + 1;
    
    fill(isPrime, isPrime + P, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 0; i < P; i++) {
        if (!isPrime[i]) continue;
        for (int j = i + i; j < P; j = j + i) {
            isPrime[j] = false;
        }
    }
    for (int i = 0; i < P; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
    cout << phi(N) << '\n';
    
    return 0;    
}
