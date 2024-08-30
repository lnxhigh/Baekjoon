#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Euler's theorem in geometry
ll solve(ll R, ll r) {
    return R*R - 2*R*r;
}

int main() {
    ll R, r;
    cin >> R >> r;
    cout << solve(R, r) << '\n';
    return 0;
}
