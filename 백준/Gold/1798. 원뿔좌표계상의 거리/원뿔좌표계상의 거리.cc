#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const double PI = acos(-1);

double r, h, d1, a1, d2, a2;

double solve() {
    double theta = abs(a2 - a1) / 180.0 * PI;
    theta = min(theta, 2.0 * PI - theta);
    double phi = (r * theta) / sqrt(r * r + h * h);
    
    double len = sqrt(d1 * d1 + d2 * d2 - 2.0 * d1 * d2 * cos(phi));
    return len;
}

int main() {
    FastIO
    cout << fixed << setprecision(2);

    while (cin >> r >> h >> d1 >> a1 >> d2 >> a2) {
        cout << solve() << '\n';
    }
    
    return 0;
}
