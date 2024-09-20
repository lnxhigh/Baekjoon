#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1000000;
int64 N, X;

int f(int64 N, int64 K) {
    // Find all X satisfying [N / X] = K
    // i.e. Find A <= X <= B such that 
    // K * X <= N < (K+1) * X
    int64 A = N / (K + 1) + 1;
    int64 B = N / K;

    // Return sum
    int64 S = (B - A + 1) * (A + B) / 2;
    return ((S % MOD) * (K % MOD)) % MOD;
}

int main() {
    cin >> N;
    
    // The possible values of [N / i] are limited
    unordered_set<int64> counts;
    for (int64 i = 1; i * i <= N; i++) {
        counts.insert(i);
        counts.insert(N / i);
    }
    
    for (int64 k : counts) {
        X += f(N, k);
        X %= MOD;
    }

    // 1 and N is not a divisor
    X -= N;
    X -= N * (N + 1) / 2;
    X++;
    
    X %= MOD;
    if (X < 0) X += MOD;
    cout << X << '\n';
    return 0;
}
