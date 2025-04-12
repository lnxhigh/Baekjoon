#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve(ll n, ll k) {
    ll a = n, b = k - n - 1;
    if (b < 0) return false;
    
    ll d = a * a - 4 * b;
    if (d < 0) return false;

    ll sq = sqrt(d);
    if (d != sq * sq) return false;

    ll x = (a + sq) / 2;
    ll y = (a - sq) / 2;

    return x + y == a && x * y == b;
}

int main() {
    ll n, k; cin >> n >> k;
    string ans = solve(n, k) ? "YES" : "NO";
    cout << ans << '\n';
    return 0;
}
