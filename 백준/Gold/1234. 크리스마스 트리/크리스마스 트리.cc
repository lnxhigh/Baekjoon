#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int MAX = 101;

int64 C[MAX][MAX];
int64 D[11][MAX][MAX][MAX];

int64 choose(int n, int k) {
    if (k == 0 || k == n) return C[n][k] = 1;
    return C[n][k] = choose(n - 1, k - 1) + choose(n - 1, k);
}

int64 dfs(int k, int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0) return 0;
    if (D[k][x][y][z] != -1) return D[k][x][y][z];
    else if (k == 0) return D[k][x][y][z] = 1;

    int64 one = 0, two = 0, three = 0;

    // One Color
    one += dfs(k - 1, x - k, y, z);
    one += dfs(k - 1, x, y - k, z);
    one += dfs(k - 1, x, y, z - k);

    // Two Color
    if (k % 2 == 0) {
        two += dfs(k - 1, x - k / 2, y - k / 2, z);
        two += dfs(k - 1, x - k / 2, y, z - k / 2);
        two += dfs(k - 1, x, y - k / 2, z - k / 2);
        two *= choose(k, k / 2);
    }
    
    // Three Color
    if (k % 3 == 0) {
        three += dfs(k - 1, x - k / 3, y - k / 3, z - k / 3);
        three *= choose(k, k / 3);
        three *= choose(k - k / 3, k / 3);
    }

    return D[k][x][y][z] = one + two + three;
}

int main() {
    memset(D, -1, sizeof(D));
    int N; cin >> N;
    int R, G, B; cin >> R >> G >> B;

    int64 ans = dfs(N, R, G, B);
    cout << ans << '\n';
    return 0;
}
