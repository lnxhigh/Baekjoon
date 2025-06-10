#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

ll n;
vector<ll> arr;

int main() {
    FastIO

    cin >> n;
    arr.resize(n);
    for (ll& x : arr) cin >> x;
    for (int i = 1; i < n; i++) arr[i] += arr[i - 1];
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll x = arr[n - 1] - arr[i] * 2;
        ans += max(x, -x - 1);
    }

    cout << ans << '\n';
    return 0;
}
