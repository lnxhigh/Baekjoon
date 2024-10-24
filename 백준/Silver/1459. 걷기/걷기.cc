#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int64 solve(int64 X, int64 Y, int64 W, int64 S) {
    if (S >= (W << 1)) return (X + Y) * W;

    int64 T = 0;
    
    int64 M = min(X, Y);
    X -= M, Y -= M;
    T += M * S;

    int64 D = max(X, Y);
    if (D == 0) return T;
    
    T += min((D >> 1) * (S << 1) + (D & 1) * W, D * W);
    return T;
}

int main() {
    int64 X, Y, W, S;
    cin >> X >> Y >> W >> S;
    cout << solve(X, Y, W, S) << '\n';
    return 0;
}
