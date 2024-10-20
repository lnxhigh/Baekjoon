#include <bits/stdc++.h>
using namespace std;
using Point = pair<int,int>;

int dist(const Point &A, const Point &B) {
    auto [x1, y1] = A;
    auto [x2, y2] = B;
    
    int dx = x1 - x2;
    int dy = y1 - y2;
    return dx * dx + dy * dy;
}

int main() {
    int xs, ys; cin >> xs >> ys;
    int xe, ye; cin >> xe >> ye;
    Point to  = { xs, ys };
    Point cur = { xe, ye };

    int dx, dy; cin >> dx >> dy;
    int g = gcd(dx, dy);
    dx /= g, dy /= g;

    while (true) {
        auto [x, y] = cur;
        Point next = { x + dx, y + dy };
        if (dist(next, to) > dist(cur, to)) break;
        cur = next;
    }

    auto [x, y] = cur;
    cout << x << ' ' << y << '\n';
    return 0;
}
