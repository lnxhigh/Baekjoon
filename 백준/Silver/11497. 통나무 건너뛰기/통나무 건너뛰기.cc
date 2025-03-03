#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO
    int T; cin >> T;
    
    while (T--) {
        int N; cin >> N;
        vector<int> L(N);
        for (int &x : L) cin >> x;

        sort(L.begin(), L.end());
        
        int ans = max(L[1] - L[0], L[N - 1] - L[N - 2]);
        for (int i = 0; i + 2 < N; i++) {
            ans = max(ans, L[i + 2] - L[i]);
        }
        
        cout << ans << '\n';
    }

    return 0;
}
