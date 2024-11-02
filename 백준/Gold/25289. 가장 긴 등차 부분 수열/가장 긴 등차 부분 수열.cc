#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N;
vector<int> A;

int solve(int r) {
    vector<int> D(101);

    int ret = 1;
    for (int i = 0; i < N; i++) {
        int k = max(A[i] - r, 0);
        D[A[i]] = max(D[A[i]], D[k] + 1);
        ret = max(ret, D[A[i]]);
    }

    return ret;
}

int main() {
    FastIO
    cin >> N;
    A.resize(N);
    for (int &X : A) cin >> X;

    int ans = 1;
    for (int r = 0; r < 100; r++) {
        ans = max(ans, solve(r));
    }
    reverse(A.begin(), A.end());
    for (int r = 0; r < 100; r++) {
        ans = max(ans, solve(r));
    }

    cout << ans << '\n';
    return 0;
}
