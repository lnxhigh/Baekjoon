#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
map<pair<int64,int64>,int64> lines; 

// overflow ...

int main() {
    FastIO
    int64 N; cin >> N;
    for (int64 i = 0; i < N; i++) {
        int64 a, b, c; cin >> a >> b >> c;
        int64 g = gcd(a, b);
        a /= g, b /= g;
        if (a < 0) a = -a, b = -b;
        else if (a == 0) b = abs(b);
        
        pair<int64,int64> p = { a, b };
        lines[p]++;
    }

    int64 ans = N * (N - 1) / 2;
    for (const auto& [p, cnt] : lines) {
        ans -= cnt * (cnt - 1) / 2;
    }
    cout << ans << '\n';
    return 0;
}
