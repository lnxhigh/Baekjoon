#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

int main() {
    FastIO
    while (true) {
        ll A; cin >> A;
        if (A == 0) break;

        int res = 0;
        ll AA = A * A;

        for (ll i = 1; i <= A; i++) {
            if (AA % i != 0) continue;
            
            ll X = i, Y = AA / i;
            if ((Y + X) & 1) continue;

            ll B = (Y - X) / 2;
            if (A < B) res++;
        }

        cout << res << '\n';
    }

    return 0;
}
