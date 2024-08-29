#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using Point = pair<double,double>;

double dist(Point A, Point B) {
    double dx = A.X - B.X;
    double dy = A.Y - B.Y;
    return sqrt(dx*dx + dy*dy);
}

double solve(Point A, Point B, Point C, Point D) {
    double u1x = B.X - A.X, u1y = B.Y - A.Y;
    double u2x = D.X - C.X, u2y = D.Y - C.Y;
    double u12x = A.X - C.X, u12y = A.Y - C.Y;
    
    double p = u1x - u2x, q = u12x;
    double r = u1y - u2y, s = u12y;

    double res = min(dist(A, C), dist(B, D));
    if (p == 0 && q == 0) return res;

    double t = -(p*q + r*s) / (p*p + r*r);
    if ((t < 0) || (t > 1)) return res;

    Point E = { A.X + u1x * t, A.Y + u1y * t };
    Point F = { C.X + u2x * t, C.Y + u2y * t };
    res = min(res, dist(E, F));

    return res;
}

int main() {
    double Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
    cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy;
    Point A = { Ax, Ay }, B = { Bx, By }, C = { Cx, Cy }, D = { Dx, Dy };
    
    double res = solve(A, B, C, D);
    cout << setprecision(16) << res << '\n';
    return 0;
}
