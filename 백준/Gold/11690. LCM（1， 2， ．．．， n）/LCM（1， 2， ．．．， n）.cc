#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1LL << 32;

int main() {
    int64 N; cin >> N;
    vector<bool> P(N + 1, true);
    P[0] = P[1] = false;
    
    for (int64 i = 0; i <= N; i++) {
        if (!P[i]) continue;
        for (int64 j = i + i; j <= N; j += i) {
            P[j] = false;
        }
    }

    int64 r = 1;
    for (int64 i = 0; i <= N; i++) {
        if (!P[i]) continue;
        for (int64 x = i; x <= N; x *= i) {
            r = r * i % MOD;
        }
    }

    cout << r << '\n';
    return 0;
}
