#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 7;

int R, C, K;
bool A[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

int dfs(int x, int y) {
    int res = 0;

    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if (A[nx][ny] || visited[nx][ny]) continue;
        res += dfs(nx, ny);
    }
    
    return ++res;
}

int main() {
    FastIO

    cin >> R >> C >> K;
    
    while (K--) {
        int a, b, x, y;
        cin >> b >> a >> y >> x;
        for (int i = a; i < x; i++) {
            for (int j = b; j < y; j++) {
                A[i][j] = true;
            }
        }
    }

    vector<int> areas;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (A[i][j] || visited[i][j]) continue;
            int area = dfs(i, j);
            areas.push_back(area);
        }
    }

    sort(areas.begin(), areas.end());
    cout << areas.size() << '\n';
    for (int area : areas) cout << area << ' ';
    cout << '\n';

    return 0;
}
