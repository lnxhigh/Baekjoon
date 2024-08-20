#include <bits/stdc++.h>
using namespace std;

double ax, ay, az;
double bx, by, bz;
double px, py, pz;

struct Point {
    double x, y, z;

    bool operator==(const Point &other) const {
        return x == other.x && y == other.y && z == other.z;
    }
    Point operator+(const Point &other) const {
        return { x + other.x, y + other.y, z + other.z };
    }
    Point operator-(const Point &other) const {
        return { x - other.x, y - other.y, z - other.z };
    }
    Point operator*(double k) {
        return { k*x, k*y, k*z };
    }
    double operator*(const Point &other) const {
        return x * other.x + y * other.y + z * other.z;
    }
};

double dist(const Point &A, const Point &B) {
    double dx = A.x - B.x, dy = A.y - B.y, dz = A.z - B.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

double solve(Point A, Point B, Point P) {
    if (A == B) return dist(P, A);

    Point U = B - A;
    double t = (U * (P - A)) / (U * U);
    Point H = A + U * t;
    
    bool in = (H - A) * (H - B) <= 0;
    double res = in ? dist(P, H) : min(dist(P, A), dist(P, B));
    return res;
}

int main() {
    cin >> ax >> ay >> az >> bx >> by >> bz;
    cin >> px >> py >> pz;

    Point A = { ax, ay, az }, B = { bx, by, bz };
    Point P = { px, py, pz };

    cout << setprecision(16);
    cout << solve(A, B, P) << '\n';
    return 0;
}
