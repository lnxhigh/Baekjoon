#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;

int main() {
    FastIO
    int64 N; cin >> N;
    vector<int64> A(N);
    int64 X = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        X += A[i];
    }

    sort(A.begin(), A.end());
    int64 S = max(
        2LL * A[0]   * A[1]   - A[0]   - A[1], 
        2LL * A[N-1] * A[N-2] - A[N-1] - A[N-2]
    );
    
    X += max(S, 0LL);
    cout << X << '\n';
    return 0;
}
