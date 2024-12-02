#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

struct Point {
    int X, Y;
    Point(): X(0), Y(0) { }
    Point(int __X, int __Y): X(__X), Y(__Y) { }

    bool operator==(const Point &other) const {
        return X == other.X && Y == other.Y;
    }
    bool operator<(const Point &other) const {
        if (X == other.X) return Y < other.Y;
        return X < other.X;
    }
    bool operator<=(const Point &other) const {
        if (X == other.X) return Y <= other.Y;
        return X <= other.X;
    }
    bool operator>(const Point &other) const {
        if (X == other.X) return Y > other.Y;
        return X > other.X;
    }
    bool operator>=(const Point &other) {
        if (X == other.X) return Y >= other.Y;
        return X >= other.X;
    }
};

int ccw(const Point &A, const Point &B, const Point &C) {
    int64_t x1 = B.X - A.X, y1 = B.Y - A.Y;
    int64_t x2 = C.X - A.X, y2 = C.Y - A.Y;
    int64_t det = x1 * y2 - x2 * y1;
    
    if (det == 0) return 0;
    return det / abs(det);
}

void swap(Point &A, Point &B) {
    Point temp = A;
    A = B;
    B = temp;
}

struct Line { 
    Point A, B;
    Line(): A(Point()), B(Point()) {}
    Line(Point __A, Point __B) {
        if (__A > __B) swap(__A, __B);
        A = __A; B = __B;
    }
};

bool cross(const Line &X, const Line &Y) {
    Point A = X.A, B = X.B;
    Point C = Y.A, D = Y.B;

    int abc = ccw(A, B, C), abd = ccw(A, B, D);
    int cda = ccw(C, D, A), cdb = ccw(C, D, B);

    int l = abc * abd, r = cda * cdb;
    if (l == 0 and r == 0) {
        return A <= D && C <= B;
    }
    return l <= 0 && r <= 0;
}

struct Rect { 
    Point P[4];
    Line L[4];
    
    Rect() {
        for (int i = 0; i < 4; i++) {
            P[i] = Point();
            L[i] = Line();
        }
    }

    Rect(Point __A, Point __B) {
        int xmin = min(__A.X, __B.X);
        int xmax = max(__A.X, __B.X);
        int ymin = min(__A.Y, __B.Y);
        int ymax = max(__A.Y, __B.Y);

        P[0] = Point(xmax, ymax);
        P[1] = Point(xmin, ymax);
        P[2] = Point(xmin, ymin);
        P[3] = Point(xmax, ymin);

        for (int i = 0; i < 4; i++) {
            L[i] = Line(P[i], P[(i + 1) % 4]);
        }
    }
};

bool cross(const Rect& A, const Rect& B) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (cross(A.L[i], B.L[j])) 
                return true;

    return false;
}

int P[MAX];
int G[MAX];

int find(int x) {
    if (P[x] == x) return x;
    return P[x] = find(P[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;

    if (x > y) P[x] = y;
    else P[y] = x;
    return true;
}

int N;
Rect R[MAX];

void input() {
    cin >> N;
    iota(P, P + N, 0);

    for (int i = 0; i < N; i++) {
        int X1, Y1, X2, Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;
        Point A(X1, Y1);
        Point B(X2, Y2);
        R[i] = Rect(A, B);
    }
}

int solve() {
    for (int i = 0; i < N; i++) 
        for (int j = i + 1; j < N; j++) 
            if (cross(R[i], R[j])) 
                merge(i, j);

    for (int i = 0; i < N; i++) 
        G[find(i)]++;

    int ans = 0;
    for (int i = 0; i < N; i++)
        if (G[i]) ans++;

    Rect S = Rect();
    bool flag = false;
    for (int i = 0; i < N; i++)
        if (cross(S, R[i])) 
            flag = true;
    
    if (flag) ans--;

    return ans;
}

int main() {
    FastIO
    input();
    int ans = solve();
    cout << ans << '\n';
    return 0;
}
