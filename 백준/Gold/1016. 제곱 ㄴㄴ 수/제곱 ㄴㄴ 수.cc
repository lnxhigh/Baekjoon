#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int64 m, M;
vector<bool> isPrime;
vector<int64> primes;

int main() {
    cin >> m >> M;
    int64 N = (int64) sqrt(M) + 1;
    isPrime.resize(N, true);
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

    vector<bool> res(M - m + 1);
    for (const int64 &p : primes) {
        int64 q = p * p;
        int64 start = m;
        int64 r = m % q;
        if (r != 0) start += q - r;
        for (int64 i = start; i <= M; i += q) {
            res[i - m] = true;
        }
    }

    int cnt = 0;
    for (const bool &isSquare : res) {
        if (!isSquare) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
