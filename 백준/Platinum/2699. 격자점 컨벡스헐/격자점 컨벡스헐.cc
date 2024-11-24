#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

struct Point {
    int x, y;

    bool operator<(const Point &other) {
        if (y == other.y) {
            return x < other.x;
        }
        return y > other.y;
    }
};

int CCW(const Point &A, const Point &B, const Point &C) {
    int x1 = A.x - B.x, y1 = A.y - B.y;
    int x2 = A.x - C.x, y2 = A.y - C.y;

    int det = x1 * y2 - x2 * y1;
    if (det == 0) return 0;
    return det / abs(det);
}

double get_angle(const Point &P) {
    int x = P.x, y = P.y;
    double dot = x;
    double size = sqrt(x * x + y * y);
    if (size == 0) return 3.1416; // Infinity
    return dot / size;
}

double get_dist(const Point &P) {
    int x = P.x, y = P.y;
    return sqrt(x * x + y * y);
}

double get_dist(const Point &A, const Point &B) {
    int dx = A.x - B.x;
    int dy = A.y - B.y;
    return sqrt(dx * dx + dy * dy);
}

struct ConvexHull {
    int N;
    vector<Point> data;
    vector<Point> hull;
    Point S;

    void input(const vector<Point> &__data) {
        N = __data.size();
        data.resize(N);
        for (int i = 0; i < N; i++) {
            data[i] = __data[i];
        }
    }

    void normalize() {
        sort(data.begin(), data.end());
        S = *data.begin();

        for (int i = 0; i < N; i++) {
            data[i].x -= S.x;
            data[i].y -= S.y;
        }
    }

    void arrange() {
        sort(data.begin(), data.end(), [&] (const Point &A, const Point &B) {
            double x = get_angle(A);
            double y = get_angle(B);

            if (x == y) {
                return (get_dist(A) < get_dist(B));
            }
            return x > y;
        });
    }

    void construct() {
        hull.push_back(data[0]);
        hull.push_back(data[1]);
        
        for (int i = 2; i < N; i++) {
            auto nxt = data[i];
            while ((int) hull.size() >= 2) {
                auto prv = hull[(int) hull.size() - 2];
                auto cur = hull[(int) hull.size() - 1];
                if (CCW(prv, cur, nxt) >= 0) hull.pop_back();
                else break;
            }
            hull.push_back(nxt);
        }

        int size = hull.size();
        if (size >= 3 && CCW(hull[size - 2], hull[size - 1], hull[0]) >= 0) {
            hull.pop_back();
        }
    }

    void print() {
        cout << hull.size() << '\n';
        for (auto p : hull) {
            cout << S.x + p.x << ' ' << S.y + p.y << '\n';
        }
    }

    ConvexHull(const vector<Point> &__data) {
        input(__data);
        normalize();
        arrange();
        construct();
    }
};

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<Point> data;
        data.resize(N);

        for (int i = 0; i < N; i++) {
            int x, y; cin >> x >> y;
            data[i] = { x, y };
        }

        ConvexHull hull = ConvexHull(data);
        hull.print();
    }

    return 0;
}
