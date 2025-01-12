#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

bool f(int dist, int N, int S, const vector<int> &X) {
    int cnt = 1, cur = 0;
    while (cnt < S) {
        int val = X[cur] + dist;
        int nxt = lower_bound(X.begin(), X.end(), val) - X.begin();
        if (nxt >= N) break;
        
        cnt++;
        cur = nxt;
    }
    
    return cnt >= S;
}

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int N, S; cin >> N >> S;
        vector<int> X(N);
        for (int i = 0; i < N; i++) cin >> X[i];
        sort(X.begin(), X.end());

        int ans = 1;
        int low = 1, high = X[N - 1] - X[0];
        while (low <= high) {
            int mid = (low + high) / 2;
            if (f(mid, N, S, X)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        cout << ans << '\n';
    }
    
    return 0;
}
