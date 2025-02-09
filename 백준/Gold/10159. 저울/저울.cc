#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 101;

int N, M;
vector<int> graph[MAX];

int D[MAX][MAX];

int dfs(int x, int y) {
    if (D[x][y] != -1) return D[x][y];
    else if (x == y) return D[x][y] = 1;

    for (int nxt : graph[x]) {
        if (dfs(nxt, y)) return D[x][y] = 1;
    }
    return D[x][y] = 0;
}

int main() {
    FastIO
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
    }

    memset(D, -1, sizeof(D));
    for (int i = 1; i <= N; i++) {
        int cnt = N;
        for (int j = 1; j <= N; j++) {
            if (dfs(i, j) || dfs(j, i)) cnt--;
        }
        cout << cnt << '\n';
    }

    return 0;
}
