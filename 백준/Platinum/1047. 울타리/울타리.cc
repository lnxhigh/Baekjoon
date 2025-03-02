#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 41;

int N;
tuple<int,int,int> A[MAX];

int f(int xmin, int ymin, int xmax, int ymax) {
    int dx = xmax - xmin;
    int dy = ymax - ymin;
    if (dx <= 0 || dy <= 0) return N - 1;
    
    int cnt = 0;
    int len = (dx + dy) << 1;

    for (int i = 0; i < N; i++) {
        auto [w, x, y] = A[i];
        if (x < xmin || x > xmax || y < ymin || y > ymax) cnt++, len -= w;
    }

    for (int i = N - 1; i >= 0 && len > 0; i--) {
        auto [w, x, y] = A[i];
        if (x >= xmin && x <= xmax && y >= ymin && y <= ymax) cnt++, len -= w;
    }

    return cnt;
}

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y, w; cin >> x >> y >> w;
        A[i] = { w, x, y };
    }
    sort(A, A + N);

    int ans = N - 1;

    for (int w = 0; w < N; w++) {
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                for (int z = 0; z < N; z++) {
                    int xmin = get<1>(A[w]), ymin = get<2>(A[x]);
                    int xmax = get<1>(A[y]), ymax = get<2>(A[z]);
                    
                    ans = min(ans, f(xmin, ymin, xmax, ymax));
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
