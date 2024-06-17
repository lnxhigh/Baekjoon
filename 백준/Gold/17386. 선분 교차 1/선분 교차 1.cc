#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using Point = pair<int,int>;

int X1, Y1, X2, Y2;
int X3, Y3, X4, Y4;

int ccw(Point A, Point B, Point C) {
    int x1 = B.X - A.X, y1 = B.Y - A.Y;
    int x2 = C.X - A.X, y2 = C.Y - A.Y;
    long long det = 1LL * x1 * y2 - 1LL * y1 * x2;
    if (det > 0) return 1;
    else if (det < 0) return -1;
    return 0;
}

bool isIntersect(Point A, Point B, Point C, Point D) {
    int a = ccw(A, B, C) * ccw(A, B, D);
    int b = ccw(C, D, A) * ccw(C, D, B);
    return a <= 0 && b <= 0;
}

int main() {
    cin.tie(NULL);
    cin >> X1 >> Y1 >> X2 >> Y2;
    cin >> X3 >> Y3 >> X4 >> Y4;
    cout << isIntersect({X1, Y1}, {X2, Y2}, {X3, Y3}, {X4, Y4});
    return 0;
}
