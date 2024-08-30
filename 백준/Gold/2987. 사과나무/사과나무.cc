#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
#define X first
#define Y second
using namespace std;
using Point = pair<float,float>;

double area(Point A, Point B, Point C) {
    double x1 = B.X - A.X, y1 = B.Y - A.Y;
    double x2 = C.X - A.X, y2 = C.Y - A.Y;
    double det = x1 * y2 - x2 * y1;
    return det / 2;
}

void swap(Point &A, Point &B) {
    Point tmp = A; A = B; B = tmp;
}

int main() {
    FastIO
    
    double xA, yA, xB, yB, xC, yC;
    cin >> xA >> yA >> xB >> yB >> xC >> yC;
    
    Point A = { xA, yA }, B = { xB, yB }, C = { xC, yC };
    if (area(A, B, C) < 0) swap(B, C);

    int N; cin >> N;
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        double x, y;
        cin >> x >> y;
        Point P = { x, y };
        
        double a = area(P, A, B), b = area(P, B, C), c = area(P, C, A);
        if (a >= 0 && b >= 0 && c >= 0) cnt++;
    }
    
    cout << fixed << setprecision(1) << area(A, B, C) << '\n';
    cout << cnt << '\n';    
    return 0;
}
