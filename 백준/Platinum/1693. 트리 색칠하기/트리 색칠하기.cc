#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100000;
const int INF = 1 << 25;

int N, C;
vector<int> graph[MAX];
vector<int> tree[MAX];
int D[MAX][20];

void build(int cur, int prev) {
    for (int next : graph[cur]) {
        if (next != prev) {
            tree[cur].push_back(next);
            build(next, cur);
        }
    }
}

// Min cost without color
int dfs(int cur, int color) {
    if (D[cur][color]) return D[cur][color];
    if (tree[cur].empty()) return D[cur][color] = color > 1 ? 1 : 2;

    int ret = INF;
    for (int i = 1; i <= C; i++) {
        if (i == color) continue;

        int value = i;
        for (int next : tree[cur]) {
            value += dfs(next, i);
        }
        ret = min(ret, value);
    }
    
    return D[cur][color] = ret;
}

int main() {
    FastIO
    cin >> N;
    for (int i = N; i; i >>= 1) C++;

    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    build(0, -1);

    int ans = INF;
    for (int i = 1; i <= C; i++) {
        ans = min(ans, dfs(0, i));
    }

    if (N == 1) ans = 1;
    cout << ans << '\n';
    return 0;
}
