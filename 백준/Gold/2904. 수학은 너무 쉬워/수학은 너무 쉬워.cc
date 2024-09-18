#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N;
const int MAX = 1 << 20;
int A[MAX];

bool isPrime[MAX];
vector<int> primes;
int counts[MAX];

vector<int> factorization[MAX];

void sieve(int N) {
    primes.clear();
    fill(isPrime, isPrime + N, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 0; i < N; i++) {
        if (!isPrime[i]) continue;
        for (int j = i+i; j < N; j += i) {
            isPrime[j] = false;
        }
    }

    for (int i = 0; i < N; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
}

vector<int> factorize(int x) {
    vector<int> res;
    for (int p : primes) {
        if (p > x || isPrime[x]) break;

        while (x % p == 0) {
            if (x % p == 0) {
                res.push_back(p);
                x /= p;
            }
        }
    }

    if (x != 1) res.push_back(x);
    return res;
}

int main() {
    FastIO
    int N; cin >> N;
    sieve(MAX);

    for (int i = 0; i < N; i++) {
        int X; cin >> X; A[i] = X;
        vector<int> factors = factorize(X);
        factorization[X] = factors;

        for (int factor : factors) counts[factor]++;
    }

    // Max score
    unordered_map<int,int> all;

    int ans = 1;
    for (int p : primes) {
        int mul = 1;
        int total = counts[p] / N;
        if (total == 0) continue;
        
        for (int i = 0; i < total; i++) mul *= p;
        ans *= mul;
        all[p] = total;
    }

    cout << ans << '\n';

    // Counts
    int val = 0;

    for (int i = 0; i < N; i++) {
        int X = A[i];
        const vector<int> &factors = factorization[X];

        unordered_map<int,int> mp;
        for (int factor : factors) mp[factor]++;

        for (auto [p,total] : all) {
            int cur = mp[p];
            if (cur < total) val += total - cur;
        }
    }

    cout << val << '\n';
    return 0;
}
