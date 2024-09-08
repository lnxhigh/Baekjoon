#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// a_{n+1} = (2n+1) a_{n}
// a_{n} = \sum_{k=0}^{n-1} {2^{n-1-k}} \ \binom{n-1}{k} \ (n-1-k)! \ a_{k}

int main() {
    ll N; cin >> N;
    ll res = 1;
    ll DIV = 1000000009LL;

    for (ll i = 0; i < N; i++) {
        res *= 2*i + 1;
        res %= DIV;
    }
    cout << res << '\n';
    return 0;
}
