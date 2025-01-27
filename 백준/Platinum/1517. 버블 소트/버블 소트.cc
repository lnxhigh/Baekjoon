#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 19;
using int64 = long long;

int64 N;
int64 A[MAX];
int64 D[MAX], F[MAX];

int64 sum(int64 idx) {
    int64 x = 0;
    while (idx) x += F[idx], idx -= idx & -idx;
    return x;
}

void update(int64 idx, int64 val) {
    while (idx <= N) F[idx] += val, idx += idx & -idx;
}

int main() {
    FastIO
    cin >> N;
    for (int64 i = 0; i < N; i++) cin >> A[i];

    vector<pair<int64,int64>> X(N);
    for (int64 i = 0; i < N; i++) X[i] = { A[i], i };
    sort(X.begin(), X.end());

    for (int64 i = 0; i < N; i++) {
        auto [val, idx] = X[i];
        D[idx] = i;
    }

    int64 ans = 0;
    for (int64 i = N - 1; i >= 0; i--) {
        auto [val, idx] = X[i];
        int64 back = sum(idx);
        int64 forward = D[idx] - (idx - back);
        
        update(idx + 1, 1);
        ans += back + forward;
    }

    ans /= 2;
    cout << ans << '\n';
    return 0;
}
