#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
#define X first
#define Y second
using namespace std;
using Point = pair<int,int>;
using Line = pair<Point,Point>;
const int MAX = 1 << 6;
const int L = 1 << 6;

int N;
Line lines[MAX];

Point f(int dir, int len) {
    int x = 0, y = 0;

    if (dir == 1) x = -L + len, y = -L;
    else if (dir == 2) x = -L + len, y = L;
    else if (dir == 3) x = -L, y = -L + len;
    else if (dir == 4) x = L, y = -L + len;

    return { x, y };
}

int ccw(Point A, Point B, Point C) {
    int a1 = A.X - B.X, b1 = A.Y - B.Y;
    int a2 = A.X - C.X, b2 = A.Y - C.Y;

    int det = a1 * b2 - a2 * b1;
    if (det) det /= abs(det);
    return det;
}

bool check(Line P, Line Q) {
    Point A = P.X, B = P.Y;
    Point C = Q.X, D = Q.Y;

    if (A > B) swap(A, B);
    if (C > D) swap(C, D);

    int abc = ccw(A, B, C), abd = ccw(A, B, D);
    int cda = ccw(C, D, A), cdb = ccw(C, D, B);

    int x = abc * abd, y = cda * cdb;
    if (x == 0 && y == 0) {
        if (A < C && B > D) return false;
        if (C < A && D > B) return false;
        return A <= D && B >= C;
    }

    return (x <= 0) && (y <= 0);
}

int main() {
    FastIO
    cin >> N; N /= 2;

    for (int i = 0; i < N; i++) {
        int dirx, lenx, diry, leny; 
        cin >> dirx >> lenx >> diry >> leny;
        Point P = f(dirx, lenx), Q = f(diry, leny);
        lines[i] = { P, Q };
    }

    int cross = 0;
    int maxCnt = 0;

    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int k = 0; k < N; k++) {
            if (k == i) continue;
            if (check(lines[i], lines[k])) cnt++;
        }

        cross += cnt;
        maxCnt = max(maxCnt, cnt);
    }

    cross /= 2;
    cout << cross << '\n';
    cout << maxCnt << '\n';

    return 0;
}
