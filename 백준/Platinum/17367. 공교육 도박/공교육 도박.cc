#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int N;
double D[MAX][6][6][6];

double f(int x, int y, int z) {
    ++x, ++y, ++z;
    if (x == y && y == z) {
        return 10000 + x * 1000;
    }
    else if (x == y || y == z || z == x) {
        int k = (x == y) ? x : (y == z) ? y : z;
        return 1000 + k * 100;
    }
    return max({ x, y, z }) * 100;
}

// 한 번 더 던져서 기댓값이 오를 수 있다면 던진다
double dfs(int cnt, int x, int y, int z) {
    if (cnt < 0) return 0;
    else if (D[cnt][x][y][z]) return D[cnt][x][y][z];

    double cur = f(x, y, z), nxt = 0;
    for (int i = 0; i < 6; i++) {
        nxt += dfs(cnt - 1, y, z, i) / 6;
    }
    return D[cnt][x][y][z] = max(cur, nxt);
}

int main() {
    FastIO
    cin >> N;
    cout << setprecision(16);

    double ans = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
                ans += dfs(N - 3, i, j, k) / 216;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
