#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    Point() : x(0), y(0) { }
    Point(int _x, int _y) : x(_x), y(_y) { }
};

struct Circle {
    Point p;
    int r;
    Circle() : p(Point(0, 0)), r(0) { }
    Circle(Point _p, int _r) : p(_p), r(_r) { }
};

int TC;

int X1, Y1, X2, Y2;
int N;
const int N_MAX = 50;
Circle circles[N_MAX];

// check if a circle includes a point
bool check(const Point &point, const Circle &circle) {
    int dx = point.x - circle.p.x;
    int dy = point.y - circle.p.y;
    int r = circle.r;

    return dx*dx + dy*dy < r*r;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> TC;
    
    while (TC--) {
        cin >> X1 >> Y1 >> X2 >> Y2;
        cin >> N;

        int x, y, r;
        for (int i = 0; i < N; i++) {
            cin >> x >> y >> r;
            Point p = Point(x, y);
            circles[i] = Circle(p, r);
        }

        const Point S = Point(X1, Y1);
        const Point E = Point(X2, Y2);

        int res = 0;
        for (int i = 0; i < N; i++) {
            const Circle &circle = circles[i];
            if (check(S, circle) ^ check(E, circle)) res++;
        }

        cout << res << '\n';
    }
    return 0;
}
