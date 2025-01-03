#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int solve() {
    int A, B, C; cin >> A >> B >> C;
    int AB, BC, CA; cin >> AB >> BC >> CA;

    int ans = 0;
    for (int y = 0; y <= min(B, C); y++) {
        for (int z = 0; z <= min(A, C); z++) {
            if (y + z > C) break;
            int x = min(A - z, B - y);

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
