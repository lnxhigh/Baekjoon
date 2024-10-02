#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 500;

int H[MAX][MAX];

int main() {
    FastIO
    
    int R, C; cin >> R >> C;
    int B; cin >> B;

    int M = 0, m = 1 << 8;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> H[i][j];
            M = max(M, H[i][j]);
            m = min(m, H[i][j]);
        }
    }

    int minTime = 1 << 30, height = -1;
    for (int h = m; h <= M; h++) {
        int t = 0, cnt = B;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (H[i][j] > h) {
                    cnt += H[i][j] - h;
                    t += (H[i][j] - h) << 1;
                }
            }
        }
        
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (H[i][j] < h) {
                    cnt -= h - H[i][j];
                    t += h - H[i][j];
                }
            }
        }

        if (cnt < 0) continue;

        if (t <= minTime) {
            minTime = t;
            height = h;
        }
    }

    cout << minTime << ' ' << height << '\n';
    return 0;
}
