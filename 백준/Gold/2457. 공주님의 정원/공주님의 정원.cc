#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N;
int D[1234];

void init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int m1, d1, m2, d2; 
        cin >> m1 >> d1 >> m2 >> d2;
        int x = 100 * m1 + d1, y = 100 * m2 + d2;
        D[x] = max(D[x], y);
    }

    for (int i = 1; i <= 1231; i++) {
        D[i] = max(D[i], D[i - 1]);
    }
}

int solve() {
    int cnt = 0, x = 301;
    while (x < 1201) {
        if (D[x] <= x) break;
        x = D[x], cnt++;
    }
    return x >= 1201 ? cnt : 0;
}

int main() {
    FastIO
    init();
    int ans = solve();
    cout << ans << '\n';
    return 0;
}
