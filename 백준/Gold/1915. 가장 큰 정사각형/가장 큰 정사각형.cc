#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int R, C;
char A[MAX][MAX];

int D[MAX][MAX];
pair<int,int> L[MAX][MAX];

void input() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> A[i][j];
        }
    }
}

void init() {
    memset(D, -1, sizeof(D));

    for (int col = 0; col < C; col++) {
        for (int row = R - 1; row >= 0; row--) {
            int x = (A[row][col] == '1');
            if (x == 0) continue;
            else L[row][col].first = L[row + 1][col].first + x;
        }
    }

    for (int row = 0; row < R; row++) {
        for (int col = C - 1; col >= 0; col--) {
            int x = (A[row][col] == '1');
            if (x == 0) continue;
            else L[row][col].second = L[row][col + 1].second + x;
        }
    }
}

int dfs(int x, int y) {
    if (x >= R || y >= C) return 0;
    if (D[x][y] != -1) return D[x][y];
    else if (A[x][y] == '0') return D[x][y] = 0;

    auto [h, w] = L[x][y];
    int len = min(h, w);
    int sq = dfs(x + 1, y + 1) + 1;
    return D[x][y] = min(len, sq);   
}

int solve() {
    int len = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            len = max(len, dfs(i, j));
        }
    }

    int area = len * len;
    return area;
}

int main() {
    FastIO
    input();
    init();
    
    int area = solve();
    cout << area << '\n';
    return 0;
}
