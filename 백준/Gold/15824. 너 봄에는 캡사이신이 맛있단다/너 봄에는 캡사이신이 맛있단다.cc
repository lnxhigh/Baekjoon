#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int64 MOD = 1000000007;

int main() {
    FastIO
    int64 N; cin >> N;
    
    vector<int64> A(N);
    for (int64 &X : A) cin >> X;
    sort(A.begin(), A.end());

    vector<int64> P(N);
    P[0] = 1;
    for (int i = 1; i < N; i++) P[i] = (P[i-1] << 1) % MOD;

    int64 M = 0, m = 0;
    for (int i = 0; i < N; i++) {
        M += A[i] * P[i];
        m += A[i] * P[N-1-i];
        M %= MOD; m %= MOD;
    }
    
    int64 res = (M - m + MOD) % MOD;
    cout << res << '\n';
    return 0;
}
