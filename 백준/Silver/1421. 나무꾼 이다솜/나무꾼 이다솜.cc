#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, C, W;
const int MAX = 1 << 6;
ll A[MAX];

ll solve(ll len) {
    if (C >= W * len) {
        ll res = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] % len != 0) continue;
            ll tmp = 0;
            ll cnt = A[i] / len;
            ll cut = cnt - 1;
            
            tmp = max(tmp, W * len * cnt - C * cut);
            if (A[i] == len) tmp = max(tmp, W * len);

            res += tmp;
        }

        return res;
    }

    ll total = 0, cuts = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] < len) continue;

        ll cnt = A[i] / len;
        ll cut = cnt;
        if (A[i] % len == 0) cut--;

        total += cnt;
        cuts += cut;
    }

    ll res = W * len * total - C * cuts;
    return res;
}

int main() {
    cin >> N >> C >> W;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll res = 0;
    ll maxLen = *max_element(A, A + N);

    for (ll len = 1; len <= maxLen; len++) {
        res = max(res, solve(len));
    }

    cout << res << '\n';
    return 0;
}
