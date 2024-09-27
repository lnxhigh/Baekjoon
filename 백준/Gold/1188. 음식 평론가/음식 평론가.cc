#include <bits/stdc++.h>
using namespace std;

int solve(int N, int M) {
    N %= M;
    int d = gcd(N, M);
    if (d == 1) return M - 1;
    return solve(N / d, M / d) * d;
}

int main() {
    int N, M; cin >> N >> M;
    cout << solve(N, M) << '\n';
    return 0;
}
