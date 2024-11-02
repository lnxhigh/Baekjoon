#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 2357;

int N;
int A[MAX][MAX];
int D[MAX][MAX];

int f(int x1, int y1, int x2, int y2) {
    int prev = A[x1][y1];
    int next = A[x2][y2];
    if (prev > next) return 0;
    return next - prev + 1;
}

int dfs(int x, int y) {
    if (D[x][y] != -1) return D[x][y];
    if (x == 0) return D[x][y] = dfs(x, y - 1) + f(x, y - 1, x, y);
    if (y == 0) return D[x][y] = dfs(x - 1, y) + f(x - 1, y, x, y);

    int first  = dfs(x, y - 1) + f(x, y - 1, x, y);
    int second = dfs(x - 1, y) + f(x - 1, y, x, y);
    return D[x][y] = min(first, second);
}

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    memset(D, -1, sizeof(D));
    D[0][0] = 0;
    cout << dfs(N - 1, N - 1);

    return 0;
}
