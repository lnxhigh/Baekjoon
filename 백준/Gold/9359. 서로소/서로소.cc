#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;

const int MAX = 1 << 16;
bool isPrime[MAX];
vector<int64> primes;

void init() {
    primes.clear();
    fill(isPrime, isPrime + MAX, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 0; i < MAX; i++) {
        if (!isPrime[i]) continue;
        for (int j = i+i; j < MAX; j += i) {
            isPrime[j] = false;
        }
    }

    for (int i = 0; i < MAX; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
}

vector<int64> factorize(int64 N) {
    vector<int64> res;
    for (int64 p : primes) {
        if (p > N) break;
        if (N % p != 0) continue;
        res.push_back(p);
        while (N % p == 0) N /= p;
    }
    if (N > 1) res.push_back(N);

    return res;
}

int64 solve(int64 X, int64 N) {
    int64 res = 0;
    vector<int64> factors = factorize(N);
    int M = factors.size();

    for (int i = 1; i < (1 << M); i++) {
        int64 cnt = 0, mul = 1;
        for (int k = 0; k < M; k++) {
            if (i >> k & 1) {
                cnt++;
                mul *= factors[k];
            }
        }

        if (~cnt & 1) mul *= -1;
        res += X / mul;
    }
    
    return X - res;
}

int main() {
    FastIO
    int64 T; cin >> T;
    init();

    for (int t = 1; t <= T; t++) {
        int64 A, B, N; cin >> A >> B >> N;
        int64 res = solve(B, N) - solve(A-1, N);
        cout << "Case #" << t << ": " << res << '\n';
    }

    return 0;
}
