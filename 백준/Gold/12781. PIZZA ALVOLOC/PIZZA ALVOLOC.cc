#include <bits/stdc++.h>
using namespace std;

struct Point { int X, Y; };

int CCW(Point A, Point B, Point C) {
    int x1 = B.X - A.X, y1 = B.Y - A.Y;
    int x2 = C.X - A.X, y2 = C.Y - A.Y;
    int det = x1 * y2 - x2 * y1;
    return det > 0 ? 1 : det < 0 ? -1 : 0;
}

bool solve(Point A, Point B, Point C, Point D) {
    int abc = CCW(A, B, C), abd = CCW(A, B, D);
    int cda = CCW(C, D, A), cdb = CCW(C, D, B);
    return (abc * abd < 0 && cda * cdb < 0);
}

int main() {
    int ax, ay, bx, by, cx, cy, dx, dy;
    cin >> ax >> ay >> bx >> by;
    cin >> cx >> cy >> dx >> dy;
    Point A = { ax, ay }, B = { bx, by };
    Point C = { cx, cy }, D = { dx, dy };
    cout << solve(A, B, C, D) << '\n';
    return 0;
}
