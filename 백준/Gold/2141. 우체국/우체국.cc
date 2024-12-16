#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int64 MAX = 100000;

int64 N;
pair<int64,int64> X[MAX];

int main() {
    FastIO
    cin >> N;
    
    int64 mid = 0;
    for (int64 i = 0; i < N; i++) {
        int64 loc, cnt; cin >> loc >> cnt;
        mid += cnt;
        X[i] = { loc, cnt };
    }

    mid = (mid + 1) / 2;
    sort(X, X + N);

    int64 sum = 0;
    int64 idx = 0;

    while (sum < mid) {
        const auto& [loc, cnt] = X[idx++];
        sum += cnt;
    }
    
    auto [ans, _] = X[--idx];
    cout << ans << '\n';
    return 0;
}
