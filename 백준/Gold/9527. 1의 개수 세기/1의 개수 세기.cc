#include <iostream>
#define ll long long
#define N 54LL
using namespace std;

ll A, B;

ll count(ll x) {
    if (x <= 1) return 0;

    ll bits[2] = {-1, -1};
    ll cnt = 0;

    for (ll i = N-1; i >= 0; i--) {
        if (cnt >= 2) { break; }
        ll bit = ( x & (1LL << i) ) >> i;
        if (bit) { bits[cnt++] = i; }
    }
    
    ll first = bits[0], second = bits[1];
    for (ll i = first; i > second; i--) {
        x = x & ~(1LL << i);
    }
    return first * (1LL << (first - 1)) + count(x) + x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> A >> B;
    cout << count(B+1) - count(A) << '\n';
    
    return 0;    
}
