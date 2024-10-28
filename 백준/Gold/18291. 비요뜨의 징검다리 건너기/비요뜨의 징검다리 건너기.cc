#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int64 MOD = 1e9 + 7;

int main() {
    FastIO
    int T; cin >> T;

    while (T--) {
        int64 N; cin >> N; N--;
        if (N > 0) N--;
        
        int64 x = 2, y = 1;
        while (N) {
            if (N & 1) y = y * x % MOD;
            x = x * x % MOD;
            N >>= 1;
        }

        cout << y << '\n';
    }
    return 0;
}
