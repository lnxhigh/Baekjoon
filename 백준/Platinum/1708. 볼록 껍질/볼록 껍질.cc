#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#define N_MAX 100000
#define ll long long
#define X first
#define Y second
using namespace std;
using Point = pair<int,int>;

int N;
Point points[N_MAX];
vector<Point> hull;

int ccw(Point A, Point B, Point C) {
    int dir;
    ll det = 1LL * (B.X - A.X) * (C.Y - A.Y) - 1LL * (B.Y - A.Y) * (C.X - A.X);
    
    if (det > 0) dir = 1;
    else if (det < 0) dir = -1;
    else dir = 0;

    return dir;
}

double angle(const Point &point, const Point &origin) {
    double x = point.X - origin.X, y = point.Y - origin.Y;
    if (x == 0.0 && y == 0.0) return 0.0;
    double slope = y / x;

    double theta = atan(slope);
    double adj = 0.0;

    if (x >= 0 && y >= 0) adj = 0.0;
    else if (x < 0 && y >= 0) adj = M_PI;
    else if (x < 0 && y < 0) adj = M_PI;
    else adj = 2*M_PI;

    return theta + adj;
}

double dist(const Point &A, const Point &B) {
    double x = double (A.X - B.X);
    double y = double (A.Y - B.Y);
    return sqrt(x*x + y*y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = { x, y };
    }
    
    int key = 0;
    for (int i = 1; i < N; i++) {
        Point p = points[key];
        bool flag = false;

        if (points[i].Y < p.Y) flag = true;
        else if (points[i].Y == p.Y) {
            if (points[i].X < p.X) flag = true;
        }
        if (flag) key = i;
    }
    
    Point start = points[key];
    sort(points, points + N, [&start](const Point &a, const Point &b) {
        double theta1 = angle(a, start);
        double theta2 = angle(b, start);

        if (theta1 < theta2) return true;
        else if (theta1 == theta2) {
            double d1 = dist(a, start);
            double d2 = dist(b, start);
            if (d1 < d2) return true;
            else return false;
        }
        return false;
    });

    hull.push_back(points[0]);
    hull.push_back(points[1]);
    for (int i = 2; i < N; i++) {
        Point next = points[i];
        while (true) {
            if (hull.size() < 2) break;
            Point prev = *(hull.end()-2);
            Point cur = *(hull.end()-1);
            
            int dir = ccw(prev, cur, next);
            if (dir == 1) break;
            
            hull.pop_back();
        }
        hull.push_back(next);
    }

    cout << hull.size() << '\n';
    
    return 0;
}