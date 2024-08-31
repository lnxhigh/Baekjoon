#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using Point = pair<int,int>;

unordered_set<int> triangles;
int N, M;

Point f(int K) {
    return { K / N, K % N };
}

int dist(const Point &A, const Point &B) {
    int dx = A.X - B.X;
    int dy = A.Y - B.Y;
    return dx * dx + dy * dy;
}

bool isColinear(const Point &A, const Point &B, const Point &C) {
    int x1 = B.X - A.X, y1 = B.Y - A.Y;
    int x2 = C.X - A.X, y2 = C.Y - A.Y;
    int det = x1 * y2 - x2 * y1;
    return det == 0;
}

void process(int x, int y, int z) {
    if (x == y || y == z || z == x) return;
    
    Point A = f(x), B = f(y), C = f(z);
    if (isColinear(A, B, C)) return;
    
    int ab = dist(A, B), bc = dist(B, C), ca = dist(C, A);
    vector<int> v = { ab, bc, ca };
    sort(v.begin(), v.end());
    
    int tri = v[0] + (v[1] << 8) + (v[2] << 16);
    triangles.insert(tri);
    return;
}

int main() {
    cin >> N >> M;
    
    ++N; ++M;
    int A = N * M;

    for (int i = 0; i < A; i++) {
        for (int j = 0; j < A; j++) {
            for (int k = 0; k < A; k++) {
                process(i, j, k);
            }
        }
    }
    
    int res = triangles.size();
    cout << res << '\n';
    return 0;
}
