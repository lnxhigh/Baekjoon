#include <bits/stdc++.h>
using namespace std;

int xA, yA;
int xB, yB;
int xC, yC;

struct Point {
    int x, y;
    Point(int _x, int _y) {
        x = _x; y = _y;
    }
    bool operator==(const Point &other) {
        return (x == other.x && y == other.y);
    }
};

bool checkIfColinear(Point A, Point B, Point C) {
    return (B.y - A.y) * (B.x - C.x) == (B.x - A.x) * (B.y - C.y);
}

bool checkIfDuplicated(Point A, Point B, Point C) {
    return A == B || B == C || C == A;
}

double dist(Point A, Point B) {
    int dx = A.x - B.x;
    int dy = A.y - B.y;
    return sqrt(1.0 * dx * dx + 1.0 * dy * dy);
}

pair<double,double> solve(Point A, Point B, Point C) {
    if (checkIfDuplicated(A, B, C)) return { 1.0, 0.0 };
    if (checkIfColinear(A, B, C)) return { 1.0, 0.0 };
    
    double x = dist(A, B);
    double y = dist(B, C);
    double z = dist(C, A);
    
    double resMin = min({ x+y, y+z, z+x });
    double resMax = max({ x+y, y+z, z+x });

    resMin *= 2.0; resMax *= 2.0;
    return { resMin, resMax };
}

int main() {
    ios::sync_with_stdio(false);
    cin >> xA >> yA;
    cin >> xB >> yB;
    cin >> xC >> yC;
    Point A = Point(xA, yA);
    Point B = Point(xB, yB);
    Point C = Point(xC, yC);

    pair<double,double> res = solve(A, B, C);
    cout << setprecision(16);
    cout << res.second - res.first << '\n';
    return 0;
}
