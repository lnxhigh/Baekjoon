#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

// Sum of ceil( sqrt(N^2 - i^2) ) - floor( sqrt(N^2 - (i+1)^2) ) gives the answer
// This is a telescoping series and the result is
// N + the number of non square numbers among N^2 - 1^2, ... , N^2 - (N-1)^2

int main() {
    FastIO
    ll N; cin >> N; N /= 2;

    ll res = N;
    for (ll i = 1; i < N; i++) {
        ll t = N * N - i * i;
        ll s = sqrt(t);
        if (t != s * s) res++;
    }

    res *= 4;
    cout << res << '\n';
    return 0;
}
