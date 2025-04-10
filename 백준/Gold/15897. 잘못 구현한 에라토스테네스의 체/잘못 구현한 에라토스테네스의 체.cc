#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n; cin >> n;
    ll cnt = n;
    ll t = 1;

    while (t < n) {
        ll x = (n - 1) / t;
        ll s = (n - 1) / (x + 1);
        ll e = (n - 1) / x;
        
        cnt += (e - s) * x;
        t = e + 1;
    }
    
    cout << cnt << '\n';
    return 0;
}
