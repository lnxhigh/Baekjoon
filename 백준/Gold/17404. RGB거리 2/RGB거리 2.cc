#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

const int INF = 1 << 20;
const int MAX = 1 << 10;
array<int,3> A[MAX];

// D[i][color first][color last]
// 1, 2, 3, ..., i번 집에 대해 비용의 최솟값을 구한다
// 1번 집의 색과 i번 집의 색을 기록한다

int D[MAX][3][3];
enum Color { R, G, B };
vector<Color> colors = { R, G, B };

int main() {
    FastIO
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        int r, g, b;
        cin >> r >> g >> b;
        A[i] = { r, g, b };
    }

    // Initialize
    fill(&D[0][0][0], &D[MAX-1][2][2] + 1, INF);
    for (int col : colors) {
        D[1][col][col] = A[1][col];
    }

    // Fill
    for (int i = 2; i <= N; i++) {
        for (int first : colors) {
            for (int last : colors) {
                for (int prev : colors) {
                    if (last == prev) continue;
                    D[i][first][last] = min(
                        D[i][first][last], 
                        D[i-1][first][prev] + A[i][last]
                    );
                }
            }
        }
    }

    // Result
    int res = INF;
    for (int first : colors) {
        for (int last : colors) {
            if (first != last) res = min(res, D[N][first][last]);
        }
    }
    cout << res << '\n';

    return 0;
}
