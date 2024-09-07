#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

int N;
const int MAX = 1 << 18;
ll A[MAX];
ll counts[MAX];

int main() {
    cin >> N;
    ll cur; cin >> cur;
    
    for (int i = 1; i < N; i++) {
        ll next; cin >> next;

        ll cnt = 0;
        ll sign = cur > next ? 1 : cur < next ? -1 : 0;

        bool same = false;
        ll a = min(cur, next);
        ll b = max(cur, next);

        while (a < b) {
            a <<= 1;
            cnt += sign;
            if (a == b) same = true;
        }

        if (!same && cur < next) cnt++;

        cur = next;
        counts[i] = max(0LL, counts[i-1] + cnt);
    }

    long long res = 0;
    for (int i = 0; i < N; i++) {
        res += (long long) counts[i];
    }
    cout << res << '\n';

    return 0;
}
