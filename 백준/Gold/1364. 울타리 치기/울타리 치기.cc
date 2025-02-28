#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll x) {
    ll len = x / 6;
    
    ll r = x % 6;
    if (r > 0) len++;

    ll cnt = 3LL * len * (len + 1) + 1LL;
    if (r == 0) return cnt;

    len++;
    r = 6 - r;

    if (r--) cnt -= len;
    while (r--) cnt -= len - 1;
    return cnt;
}

int main() {
    int N; cin >> N;
    cout << f(N) << '\n';
}
