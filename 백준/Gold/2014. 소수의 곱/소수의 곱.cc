#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int MAX = 1 << 7;

int K, N;

int main() {
    FastIO
    cin >> K >> N;

    vector<int64> P(K);
    for (auto &x : P) cin >> x;

    vector<int64> A;
    A.reserve(N + 1);
    A.push_back(1);

    for (int i = 1; i <= N; i++) {
        int64 cur = A.back();
        int64 nxt = LLONG_MAX;

        for (int64 x : P) {
            int64 tmp = *upper_bound(A.begin(), A.end(), cur / x);
            nxt = min(nxt, x * tmp);
        }

        A.push_back(nxt);
    }

    int64 ans = A.back();
    cout << ans << '\n';
    return 0;
}
