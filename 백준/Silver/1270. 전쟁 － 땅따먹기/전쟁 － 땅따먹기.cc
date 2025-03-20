#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

int main() {
    FastIO
    int N; cin >> N;

    for (int i = 0; i < N; i++) {
        unordered_map<ll,ll> S;

        int T; cin >> T;
        assert(T > 0);
        
        ll maxNum = 0, maxCnt = 0;

        for (int k = 0; k < T; k++) {
            ll x; cin >> x;
            S[x]++;

            if (S[x] > maxCnt) {
                maxNum = x;
                maxCnt = S[x];
            }
        }

        if (maxCnt * 2 > T) {
            cout << maxNum << '\n';
        }
        else {
            cout << "SYJKGW" << '\n';
        }
    }

    return 0;
}
