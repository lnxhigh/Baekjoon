#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO
    int tc; cin >> tc;
    
    while (tc--) {
        int n; cin >> n;
        vector<int> x(n);
        for (int& i : x) cin >> i;

        int cnt = 0;
        int chk = n * (n - 1) / 2;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (x[i] < x[j]) cnt++;
            }
        }

        string ans = ((cnt & 1) == (chk & 1)) ? "YES" : "NO";
        cout << ans << '\n';
    }

    return 0;
}
