#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int n, r;
vector<int> tree[MAX];
int weight[MAX], par[MAX];
int dp[MAX][MAX];

void init(int x, int p) {
    for (int nxt : tree[x]) {
        if (nxt == p) continue;
        par[nxt] = x;
        init(nxt, x);
    }
}

int dfs(int x, int p) {
    int& ret = dp[x][p];
    if (ret != -1) return ret;

    int first = weight[x];
    for (int nxt : tree[x]) {
        if (nxt == par[x]) continue;
        first += min(dfs(nxt, x), dfs(nxt, nxt));
    }

    if (x == p) return ret = first;

    int second = weight[x] - weight[p];
    for (int nxt : tree[x]) {
        if (nxt == par[x]) continue;
        second += min(dfs(nxt, p), dfs(nxt, nxt));
    }

    return ret = min(first, second);
}

int main() {
    FastIO

    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
    }

    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        tree[x].emplace_back(y);
        tree[y].emplace_back(x);
    }

    init(r, 0);

    memset(dp, -1, sizeof(dp));
    int ans = dfs(r, r);
    cout << ans << '\n';

    return 0;
}
