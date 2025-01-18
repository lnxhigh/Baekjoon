#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = unsigned long long;

int64 f(int64 N) {
    int64 ret = 0;
    for (int i = 61; i >= 0; i--) {
        if ((N >> i & 1) == 0) continue;

        int zero = 0, one = 0;
        for (int k = i; k >= 0; k--) {
            if (N >> k & 1) one++;
            else zero++;
        }
        if (zero == 0) continue;

        int64 x = N;
        for (int k = 0; k <= i; k++) {
            x &= ~(1LL << k);
        }
        for (int k = 1; k <= one; k++) {
            x |= 1LL << (i - k);
        }

        ret = max(ret, x);
    }

    return ret;
}

int64 g(int64 N) {
    int64 ret = 1LL << 63;
    for (int i = 61; i >= 0; i--) {
        if (N >> i & 1) continue;

        int zero = 0, one = 0;
        for (int k = 0; k <= i; k++) {
            if (N >> k & 1) one++;
            else zero++;
        }
        if (one == 0) continue;

        int64 x = N;
        for (int k = 0; k <= i; k++) {
            x &= ~(1LL << k);
        }

        x |= 1LL << i;
        for (int k = 0; k < one - 1; k++) {
            x |= 1LL << k;
        }

        ret = min(ret, x);
    }

    return ret;
}

int main() {
    FastIO
    int64 N; cin >> N;
    cout << f(N) << ' ' << g(N) << '\n';
    return 0;
}
