#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const double PI = acos(-1);

struct Point {
    int X, Y;
    Point(): X(0), Y(0) { }
    Point(int __X, int __Y): X(__X), Y(__Y) { }

    double angle() const {
        double theta = atan2(Y, X);
        if (theta < 0) theta += 2.0 * PI;
        return theta;
    }
};

int ccw(const Point &A, const Point &B, const Point &C) {
    int x1 = B.X - A.X, y1 = B.Y - A.Y;
    int x2 = C.X - A.X, y2 = C.Y - A.Y;
    int det = x1 * y2 - x2 * y1;
    return (det > 0) - (det < 0);
}

struct Line {
    Point A, B;
    Line(): A(Point()), B(Point()) { }
    Line(Point __A, Point __B): A(__A), B(__B) { }
    
    bool cross (const Line &other) const {
        int x = ccw(A, B, other.A) * ccw(A, B, other.B);
        int y = ccw(other.A, other.B, A) * ccw(other.A, other.B, B);
        return x == -1 && y == -1;
    }
};

int main() {
    FastIO
    int T; cin >> T;
    cout << fixed << setprecision(5);
    
    while (T--) {
        int N; cin >> N;
        vector<Line> L(N);
        vector<Point> P(N << 1);

        for (int i = 0; i < N; i++) {
            int X1, Y1, X2, Y2; 
            cin >> X1 >> Y1 >> X2 >> Y2;
            X1 *= 2, Y1 *= 2, X2 *= 2, Y2 *= 2;
            Point A = { X1, Y1 }, B = { X2, Y2 };

            P[i * 2] = A;
            P[i * 2 + 1] = B;
            L[i] = Line(A, B);
        }

        sort(P.begin(), P.end(), [] (Point &A, Point &B) {
            return A.angle() < B.angle();
        });

        double ans = 0;
        Point origin = { 0, 0 };

        for (int i = 0; i < (N << 1); i++) {
            Point cur = P[i];
            Point nxt = P[(i + 1) % (N << 1)];

            Point to = { (cur.X + nxt.X) * 1000, (cur.Y + nxt.Y) * 1000 };
            Line arrow(origin, to);

            int cnt = 0;
            for (const Line &line : L) {
                if (line.cross(arrow)) cnt++;
            }

            double angle = atan2(nxt.Y, nxt.X) - atan2(cur.Y, cur.X);
            if (angle < 0) angle += 2.0 * PI;
            if (angle > PI) cnt = 0;
            
            ans += cnt * angle / (2.0 * PI);
        }

        cout << ans << '\n';
    }

    return 0;
}
