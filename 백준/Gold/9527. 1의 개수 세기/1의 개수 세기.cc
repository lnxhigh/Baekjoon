#include <iostream>
#define ll long long
#define N 54LL
using namespace std;

ll A, B;

ll count(ll X) {
    if (X <= 1LL) return 0LL;
    ll msb = -1LL, ssb = -1LL;

    for (ll i = N-1LL; i >= 0LL; i--) {
        ll bit = ( X & (1LL << i) ) >> i;
        if (bit) { msb = i; break; }
    }
    
    for (ll i = msb-1LL; i >= 0LL; i--) {
        ll bit = ( X & (1LL << i) ) >> i;
        if (bit) { ssb = i; break; }
    }
    
    if (ssb == -1LL) { return msb * (1LL << (msb-1LL)); }
    
    for (ll i = msb; i > ssb; i--) {
        X = X & ~(1LL << i);
    }
    return msb * (1LL << (msb-1LL)) + count(X) + X;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> A >> B;
    cout << count(B+1) - count(A);
    
    return 0;    
}
