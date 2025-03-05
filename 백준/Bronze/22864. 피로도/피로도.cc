#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, M;
    cin >> A >> B >> C >> M;

    int ans = 0, cur = 0;
    for (int t = 0; t < 24; t++) {
        if (cur + A <= M) ans += B, cur += A;
        else cur = max(cur - C, 0);
    }

    cout << ans << '\n';
    return 0;
}
