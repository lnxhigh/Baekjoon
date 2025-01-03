#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int solve() {
    int A, B, C; cin >> A >> B >> C;
    int AB, BC, CA; cin >> AB >> BC >> CA;

    int ans = 0;
    for (int y = 0; y <= C; y++) {
        for (int z = 0; z <= C; z++) {
            if (y + z > C) continue;
            int x = min(A - z, B - y);
            if (x < 0) continue;

            int cost = AB * x + BC * y + CA * z;
            ans = max(ans, cost);
        }
    }

    return ans;
}

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}
