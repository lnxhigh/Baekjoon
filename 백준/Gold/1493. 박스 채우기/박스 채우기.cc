#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

ll L, W, H;
ll N;
ll A[20];

int main() {
    FastIO
    cin >> L >> W >> H;
    cin >> N;

    while (N--) {
        ll size, cnt; 
        cin >> size >> cnt;
        A[size] += cnt;
    }

    ll ans = 0, sum = 0;

    for (ll i = 19; i >= 0; i--) {
        ll len = 1 << i;
        ll vol = len * len * len;
        ll cnt = (L / len) * (W / len) * (H / len) - (sum / vol);
        cnt = min(cnt, A[i]);
        
        ans += cnt;
        sum += vol * cnt;
    }

    if (sum < L * W * H) ans = -1;
    cout << ans << '\n';
    return 0;
}
