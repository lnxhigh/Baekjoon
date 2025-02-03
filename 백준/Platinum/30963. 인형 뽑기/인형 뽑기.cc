#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int MAX = 1 << 20;
const int64 MOD = 1'000'000'007;

int64 P; 
int C, N;
int64 D[MAX] = {1};

int main() {
    FastIO
    int T; cin >> T;
    
    while (T--) {
        cin >> P;
        C, N; cin >> C >> N;

        int64 ans = 0, mul = 1;
        for (int k = 1; k <= N; k++) {
            int64 x = (k >= C) ? D[k - C] * mul % MOD: 0;
            if (k < C) mul = mul * (MOD + 1 - P) % MOD;
            D[k] = (x + (MOD + 1 - x) * P) % MOD;
            
            ans = (D[k] * (ans + 1) + (MOD + 1 - D[k]) * ans) % MOD;
            cout << ans << '\n';
        }
    }

    return 0;
}
