#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int solve(int M, int N, int x, int y) {
    y %= N;
    int P = M * N;
    for (int i = x; i <= P; i += M) {
        if (i % N == y) return i;
    }
    return -1;
}

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        cout << solve(M, N, x, y) << '\n';
    }
    
    return 0;
}
