#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll A, B; cin >> A >> B;

    ll d = gcd(A, B);
    unordered_set<ll> ans;

    for (ll k = 1; k * k <= B; k++) {
        if (B % k != 0) continue;

        for (ll g : { k, B / k }) {
            ll C = (A / d) * g;
            if (d == gcd(A, C) && g == gcd(B, C)) {
                ans.insert(C);
            }
        }
    }

    cout << ans.size() << '\n';
    return 0;
}
