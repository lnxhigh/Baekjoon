#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int n;
double X, v;

double solve() {
    cin >> n >> X >> v;

    double sum = 0;
    for (int i = 0; i < n; i++) {
        double l, r, v;
        cin >> l >> r >> v;
        sum += (r - l) * v;
    }

    double vy = -sum / X;
    if (vy >= v) return -1;

    double vx = sqrt(v*v - vy*vy);
    double t = X / vx;

    if (t > 2.0 * X / v) return -1;
    
    return t;
}

int main() {
    FastIO
    double res = solve();
    cout << fixed << setprecision(3);
    if (res < 0) cout << "Too hard" << '\n';
    else cout << res << '\n';
    return 0;
}
