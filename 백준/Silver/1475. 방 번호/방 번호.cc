#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO
    
    int N; cin >> N;
    int D[10] = { 0 };

    while (N) {
        D[N % 10]++;
        N /= 10;
    }

    int ans = (D[6] + D[9] + 1) / 2;
    for (int i = 0; i < 10; i++) {
        if (i == 6 || i == 9) continue;
        ans = max(ans, D[i]);
    }
    
    cout << ans << '\n';
    return 0;
}

