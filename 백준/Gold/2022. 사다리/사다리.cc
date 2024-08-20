#include <bits/stdc++.h>
using namespace std;

int main() {
    double x, y, c;
    cin >> x >> y >> c;

    double res = 0.0;
    double s = 0.0, e = min(x, y);
    for (int iter = 0; iter < 100; iter++) {
        if (s > e) break;
        
        double m = (s + e) / 2.0;
        if (m == 0) break;
        
        res = m;
        
        double alpha = acos(m / x);
        double beta  = acos(m / y);
        double h = m * tan(alpha) * tan(beta) / (tan(alpha) + tan(beta));

        if      (h > c) s = m;
        else if (h < c) e = m;
        else break;
    }

    cout << setprecision(16);
    cout << res << '\n';
    return 0;
}
