#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int phi(int x) {
    if (x <= 1) return 0;
    
    int cnt = x;
    for (int i = 2; i * i <= x; i++) {
        if (x % i != 0) continue;
        while (x % i == 0) x /= i;
        cnt = cnt / i * (i - 1);
    }
    if (x != 1) cnt = cnt / x * (x - 1);
    return cnt;
}

int main() {
    FastIO
    int T; cin >> T;

    while (T--) {
        int N; cin >> N;
        int cnt = phi(N);
        if (N % 2 == 0) cnt += phi(N >> 1);
        cout << cnt << '\n';
    }

    return 0;
}
