#include <bits/stdc++.h>
using namespace std;

const int MAX = 1 << 6;
int D[MAX][MAX][MAX];

int solve(int x, int y, int z) {
    x = max(0, x), y = max(0, y), z = max(0, z);
    if (x == 0 && y == 0 && z == 0) return 0;
    if (D[x][y][z]) return D[x][y][z];

    int res = 1 << 5;
    vector<int> p = { 1, 3, 9 };
    do {
        res = min(res, solve(x - p[0], y - p[1], z - p[2]));
    } while (next_permutation(p.begin(), p.end()));
    
    return D[x][y][z] = ++res;
}

int main() {
    int H[3] = { 0, 0, 0 };
    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> H[i];

    int res = solve(H[0], H[1], H[2]);
    cout << res << '\n';
    return 0;
}
