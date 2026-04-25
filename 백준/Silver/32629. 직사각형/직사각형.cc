#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int f(int N, int x) {
    int y = (N + x - 1) / x;
    return (x + y) << 1;
}

int solve(int N) {
    int sq = sqrt(N);
    return min(f(N, sq), f(N, sq + 1));
}

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        cout << solve(N) << '\n';
    }
    return 0;
}
