#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
#define X first
#define Y second
using namespace std;
using int64 = long long;
using Point = pair<int64,int64>;

int64 dist(const Point &A, const Point &B) {
    int64 dx = A.X - B.X;
    int64 dy = A.Y - B.Y;
    return dx * dx + dy * dy;
}

bool solve() {
    Point P[4];
    for (int i = 0; i < 4; i++) {
        int64 x, y; cin >> x >> y;
        P[i] = { x, y };
    }

    vector<int64> V;
    for (int i = 0; i < 4; i++) {
        for (int j = i+1; j < 4; j++) {
            V.push_back(dist(P[i], P[j]));
        }
    }
    sort(V.begin(), V.end());

    for (int i = 0; i < 4; i++) {
        V[i] <<= 1;
    }
    
    for (int i = 0; i < 6; i++) {
        if (V[i] != V[0]) return false;
    }

    return true;
}

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}
