#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

int main() {
    FastIO
    int N; cin >> N;

    for (int i = 0; i < N; i++) {
        int T; cin >> T;
        
        vector<ll> S(T);
        for (ll& x : S) cin >> x;
        sort(S.begin(), S.end());

        ll maxNum = 0, maxCnt = 0;
        int idx = 0, first = 0;

        while (idx < T) {
            ll cnt = 0;
            while (idx < T && S[idx] == S[first]) idx++, cnt++;
            if (cnt > maxCnt) maxNum = S[first], maxCnt = cnt;
            first = idx;
        }

        string ans = (maxCnt * 2 > T) ? to_string(maxNum) : "SYJKGW";
        cout << ans << '\n';
    }

    return 0;
}
