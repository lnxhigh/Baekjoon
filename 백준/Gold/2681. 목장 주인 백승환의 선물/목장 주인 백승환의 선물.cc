#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

struct Point {
    double x = 0;
    double y = 0;
};

struct Line {
    Point p, q;
};

double dist(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double get_area(Point a, Point b, Point c) {
    double det = (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
    return 0.5 * abs(det);
}

Point cross(Line one, Line other) {
    double x1 = one.p.x, x2 = one.q.x, y1 = one.p.y, y2 = one.q.y;
    double a1 = other.p.x, a2 = other.q.x, b1 = other.p.y, b2 = other.q.y;

    double a = -(x2 - x1), b = (a2 - a1), e = (x1 - a1);
    double c = -(y2 - y1), d = (b2 - b1), f = (y1 - b1);

    double num = d * e - b * f;
    double den = a * d - b * c;
    double t = num / den;

    double cx = x1 + (x2 - x1) * t, cy = y1 + (y2 - y1) * t;
    return { cx, cy };
}

pair<double,Point> f(Point a, Point b, Point c, Point d) {
    Point ap = { (b.x + c.x) / 2, (b.y + c.y) / 2 };
    Point bp = { (c.x + d.x) / 2, (c.y + d.y) / 2 };

    Line one = { a, ap }, other = { b, bp };

    Point x = cross(one, other);

    double area = get_area(a, b, x);
    return { area, x };
}

pair<vector<double>, long long> solve(Point a, Point b, Point c, Point d) {
    vector<double> areas;
    vector<Point> points;
    double len = 0;

    Point arr[4] = { a, b, c, d };
    for (int i = 0; i < 4; i++) {
        auto [area, x] = f(arr[i], arr[(i + 1) % 4], arr[(i + 2) % 4], arr[(i + 3) % 4]);
        
        areas.push_back(area);
        points.push_back(x);
    }

    double rem = get_area(a, b, c) + get_area(c, d, a);

    for (int i = 0; i < 4; i++) {
        rem -= areas[i];
        len += dist(points[i], points[(i + 1) % 4]);
    }

    areas.push_back(rem);
    return { areas, (long long) ceil(len) };
}

int main() {
    FastIO
    int t; cin >> t;
    while (t--) {
        Point a, b, c, d;
        cin >> b.x >> c.x >> c.y >> d.x >> d.y;
        auto [areas, len] = solve(a, b, c, d);

        cout << fixed << setprecision(3);
        for (double area : areas) cout << area << ' ';
        cout << len << '\n';
    }

    return 0;
}
