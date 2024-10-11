#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
// https://casterian.net/algorithm/중국인의-나머지-정리

tuple<int64,int64,int64> euclidean(int64 a, int64 b) {
    if (b == 0) return { a, 1, 0 };
    auto [ g, x, y ] = euclidean(b, a % b);
    return { g, y, x - (a / b) * y };
}

int64 inverse(int64 a, int64 b) {
    auto [ g, x, y ] = euclidean(a, b);
    return (x % b + b) % b;
}

int64 crt(const vector<pair<int,int>> &info) {
    int64 M = 1;
    for (const auto& [i, r] : info) M *= i;

    int64 res = 0;
    for (const auto& [i, r] : info) {
        int64 Mi = M / i;
        int64 yi = inverse(Mi, i);
        res += Mi * yi * r;
    }

    return res % M;
}

int64 solve(int64 M, int64 N, int64 x, int64 y) {
    --x, --y;
    auto [g, k0, _] = euclidean(M, N);
    if (x % g != y % g) return -1;
    
    k0 *= (y - x) / g; // 특수해
    int k = (M * k0 + x) % (M * N / g);
    if (k < 0) k += M * N / g;
    return ++k;
}

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int64 M, N, x, y;
        cin >> M >> N >> x >> y;
        cout << solve(M, N, x, y) << '\n';
    }
}