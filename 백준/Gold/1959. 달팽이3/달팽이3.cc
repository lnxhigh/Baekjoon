#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

int main() {
    FastIO
    ll R, C; 
    cin >> R >> C;

    ll cnt = 0;
    ll x = 1, y = 1;

    if (R > 2 && C > 2) {
        ll len = min(R, C);
        ll t = (len % 2 != 0) ? len / 2 : len / 2 - 1;
        
        cnt += t * 4;
        x += t, y += t;
        R -= 2 * t, C -= 2 * t;
    }

    if      (R == 1) cnt += 0, y += C - 1;
    else if (C == 1) cnt += 1, x += R - 1;
    else if (R == 2) cnt += 2, x++;
    else if (C == 2) cnt += 3, x++;

    cout << cnt << '\n';
    cout << x << ' ' << y << '\n';

    return 0;
}
