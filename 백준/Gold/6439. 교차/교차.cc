#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using Point = pair<int,int>;
using Line = pair<Point,Point>;

int TC;

int ccw(Point A, Point B, Point C) {
    int x1 = B.X - A.X, y1 = B.Y - A.Y;
    int x2 = C.X - A.X, y2 = C.Y - A.Y;
    int det = x1 * y2 - y1 * x2;

    if (det == 0) return det;
    return det / abs(det);
}

void swap(int &x, int &y) {
    int tmp = x; x = y; y = tmp;
}

void swap(Point &A, Point &B) {
    Point tmp = A; A = B; B = tmp;
}

bool isIntersect(Line F, Line S) {
    Point A = F.X, B = F.Y;
    Point C = S.X, D = S.Y;

    int abc = ccw(A, B, C), abd = ccw(A, B, D);
    int cda = ccw(C, D, A), cdb = ccw(C, D, B);

    int x = abc * abd, y = cda * cdb;
    if (x == 0 && y == 0) {
        if (A > B) swap(A, B);
        if (C > D) swap(C, D);
        return (A <= D && C <= B);
    }

    return (x <= 0 && y <= 0);
}

bool solve(Line line, vector<Line> rect) {
    // check if the line is inside the rect
    vector<Point> points = { line.X, line.Y };
    
    Point bl = rect[0].X, tr = rect[2].X;
    int minX = bl.X, minY = bl.Y;
    int maxX = tr.X, maxY = tr.Y;

    for (Point point : points) {
        bool isInside = true;
        if (point.X < minX || point.X > maxX) isInside = false;
        if (point.Y < minY || point.Y > maxY) isInside = false;
        if (isInside) return true;
    }

    // check if the line is intersect with rect
    for (Line rectline : rect) {
        if (isIntersect(line, rectline)) return true;
    }
    return false;
}

int main() {
    cin >> TC;
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    while (TC--) {
        int xstart, ystart, xend, yend, xleft, ytop, xright, ybottom;
        cin >> xstart >> ystart >> xend >> yend >> xleft >> ytop >> xright >> ybottom;
        if (xleft > xright) swap(xleft, xright);
        if (ybottom > ytop) swap(ybottom, ytop);
        
        Point A = { xleft,  ybottom }, B = { xright, ybottom };
        Point C = { xright, ytop    }, D = { xleft , ytop    };
        Point P = { xstart, ystart  }, Q = { xend  , yend    };

        Line line = { P, Q };
        vector<Line> rect = { {A, B}, {B, C}, {C, D}, {D, A} };
        char res = solve(line, rect) ? 'T' : 'F';
        cout << res << '\n';
    }

    return 0;
}
