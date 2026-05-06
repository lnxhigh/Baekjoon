#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll floor(ll x, ll y) {
    return x / y;
}

ll ceil(ll x, ll y) {
    return (x + y - 1) / y;
}

ll solution(int w, int h) {
    ll cnt = (ll) w * h;
    for (ll x = 0; x < w; x++) {
        ll low = floor(x * h, w);
        ll high = ceil((x + 1) * h, w);
        cnt -= high - low;
    }

    return cnt;
}
