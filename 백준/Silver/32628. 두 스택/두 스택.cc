#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;

int main() {
    FastIO
    int64 N, K; cin >> N >> K;
    vector<int64> A(N), B(N);
    
    for (int64 &k : A) cin >> k;
    for (int64 &k : B) cin >> k;
    reverse(A.begin(), A.end());

    vector<int64> X(N << 1);
    for (int i = 0; i < N; i++) X[i] = A[i];
    for (int i = 0; i < N; i++) X[i + N] = B[i];

    int64 M = (N << 1) - K;
    
    vector<int64> S(N << 1);
    S[0] = X[0];
    for (int i = 1; i < (N << 1); i++) {
        S[i] = X[i] + S[i - 1];
    }

    int64 ans = 1LL << 60;
    for (int i = 0; i < (N << 1); i++) {
        if (i > N || i + M <= N - 1 || i + M > (N << 1)) continue;

        int64 a = S[N - 1];
        if (i > 0) a -= S[i - 1];
        
        int64 b = S[i + M - 1];
        b -= S[N - 1];

        ans = min(ans, max(a, b));
    }

    cout << ans << '\n';
    return 0;
}
