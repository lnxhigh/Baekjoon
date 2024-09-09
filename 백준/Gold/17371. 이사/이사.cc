#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
#define X first
#define Y second
using namespace std;
using Point = pair<int,int>;

int N;
const int MAX = 1 << 10;
Point P[MAX];
int D[MAX];

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        P[i] = { x, y };
    }

    for (int i = 0; i < N; i++) {
        const Point &me = P[i];
        for (int k = 0; k < N; k++) {
            const Point &other = P[k];
            int dx = me.X - other.X;
            int dy = me.Y - other.Y;
            D[i] = max(D[i], dx*dx + dy*dy);
        }
    }

    int k = min_element(D, D + N) - D;
    cout << P[k].X << ' ' << P[k].Y << '\n';
    return 0;
}
