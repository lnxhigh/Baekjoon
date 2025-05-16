#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int n;
double px[50], py[50], vx[50], vy[50];

double f(double t) {
    double minx, maxx, miny, maxy;

    for (int i = 0; i < n; i++) {
        double x = px[i] + vx[i] * t, y = py[i] + vy[i] * t;
        if (i) minx = min(minx, x), maxx = max(maxx, x), miny = min(miny, y), maxy = max(maxy, y);
        else minx = x, maxx = x, miny = y, maxy = y;
    }

    return max(maxx - minx, maxy - miny);
}

int main() {
    FastIO

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> px[i] >> py[i] >> vx[i] >> vy[i];
    }
    
    double lo = 0, hi = 1e12;
    double eps = 1e-15;

    int iter = 0;
    int max_iter = 10000;

    while (hi > lo && hi - lo > eps && iter < max_iter) {
        double delta = (hi - lo) / 3;
        double p = lo + delta, q = hi - delta;
        (f(p) < f(q)) ? hi = q : lo = p;

        iter++;
    }

    double t = (lo + hi) / 2;
    double ans = f(t);

    cout << setprecision(16);
    cout << ans << '\n';

    return 0;
}
