#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

// https://casterian.net/algorithm/확장-유클리드-호제법

// Find [ gcd, x, y ] s.t. ax + by = gcd(a, b);

// ax + by = gcd(a, b)
// a = bq + r => b(qx+y) + rx = gcd(b, r)

// Let x*, y* be the solution of f(b, r)
// Then x* = qx + y, y* = x
// i.e. x = y*, y = x* - qy*

tuple<int64,int64,int64> f(int64 a, int64 b) {
    if (b == 0) return { a, 1, 0 };
    auto [ g, x, y ] = f(b, a % b);
    return { g, y, x - (a / b) * y };
}

int64 add(int64 N, int64 A) {
    return N - A;
}

// General Solution [ x, y ]
// Ax + By = Ax0 + By0 = C
// x = x0 + k * B / g
// y = y0 - k * A / g

int64 mul(int64 N, int64 A) {
    auto [ g, x, y ] = f(N, A);
    if (g != 1) return -1;
    return y >= 0 ? y % N : y % N + N;
}

int main() {
    int64 N, A; cin >> N >> A;
    cout << add(N, A) << ' ' << mul(N, A) << '\n';
    return 0;
}
