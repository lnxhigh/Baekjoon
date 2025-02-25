#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

struct Point {
    int x, y;
    Point(): x(0), y(0) { }
    Point(int a, int b): x(a), y(b) { }
    int dot(const Point& other) { return x * other.x + y * other.y; }
};

struct Rect {
    Point o;
    Point u, v;

    Rect() { }
    
    Rect(Point* P) {
        int cx = (P[0].x + P[2].x) / 2;
        int cy = (P[0].y + P[2].y) / 2;

        int a1 = (P[0].x + P[1].x) / 2;
        int b1 = (P[0].y + P[1].y) / 2;
        int a2 = (P[1].x + P[2].x) / 2;
        int b2 = (P[1].y + P[2].y) / 2;

        o = Point(cx, cy);
        u = Point(a1 - cx, b1 - cy);
        v = Point(a2 - cx, b2 - cy);
    }
};

bool check(Rect X, Rect Y) {
    bool flag = false;
    Point P[4] = { X.u, X.v, Y.u, Y.v };
    Point d = Point(X.o.x - Y.o.x, X.o.y - Y.o.y);

    for (int i = 0; i < 4; i++) {
        Point u = P[i];
        int lhs = abs(d.dot(u));
        int rhs = abs(X.u.dot(u)) + abs(X.v.dot(u)) + abs(Y.u.dot(u)) + abs(Y.v.dot(u));
        if (lhs >= rhs) flag = true;
    }

    // Return negation
    return !flag;
}

int main() {
    FastIO
    
    Point P[4], Q[4];

    for (int i = 0; i < 4; i++) {
        int x, y; cin >> x >> y;
        x *= 2, y *= 2;
        P[i] = Point(x, y);
    }

    for (int i = 0; i < 4; i++) {
        int x, y; cin >> x >> y;
        x *= 2, y *= 2;
        Q[i] = Point(x, y);
    }

    Rect X(P), Y(Q);
    bool ans = check(X, Y);
    cout << ans << '\n';

    return 0;
}
