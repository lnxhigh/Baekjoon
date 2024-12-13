#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;

int main() {
    FastIO
    int64 N, K; cin >> N >> K;
    vector<int64> D(N - 1);
    
    int64 x = 0; cin >> x;
    int64 y = 0;
    
    for (int64 i = 0; i < N - 1; i++) {
        cin >> y;
        int64 diff = y - x;
        D[i] = diff;
        x = y;
    }

    sort(D.begin(), D.end());
    int64 ans = 0;
    for (int64 i = 0; i < N - K; i++) {
        ans += D[i];
    }
    cout << ans << '\n';
    return 0;
}
