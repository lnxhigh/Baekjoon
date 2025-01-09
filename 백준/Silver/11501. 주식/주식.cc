#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int64> A(N), D(N);
        for (int64 &X : A) cin >> X;
        
        D[N - 1] = A[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            D[i] = max(A[i], D[i + 1]);
        }

        int64 ans = 0;
        for (int i = 0; i < N - 1; i++) {
            int64 cur = A[i];
            int64 nxt = D[i + 1];

            int64 profit = nxt - cur;
            if (profit > 0) ans += profit;
        }

        cout << ans << '\n';
    }
    
    return 0;
}
