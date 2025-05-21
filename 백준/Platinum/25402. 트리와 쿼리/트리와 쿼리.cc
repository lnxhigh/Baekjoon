#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 250'001;

int n, q;
vector<int> tree[MAX];

int pre[MAX]; // tree parent
bool chk[MAX];
int par[MAX], sz[MAX]; // union-find

void dfs(int cur, int prv) {
    for (int nxt : tree[cur]) {
        if (nxt == prv) continue;
        pre[nxt] = cur;
        dfs(nxt, cur);
    }
}

int find(int x) {
    if (par[x] == 0) return x;
    return par[x] = find(par[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    else if (x < y) swap(x, y);

    par[x] = y, sz[y] += sz[x];
    return true;
}

int main() {
    FastIO
    
    // Tree

    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        tree[x].emplace_back(y);
        tree[y].emplace_back(x);
    }

    dfs(1, 0);
    fill(sz, sz + MAX, 1);

    // Query
    
    cin >> q;
    while (q--) {
        int k; cin >> k;
        vector<int> nodes(k);
        for (auto& x : nodes) cin >> x, chk[x] = true;

        long long ans = 0;

        for (auto x : nodes) {
            int p = pre[x];
            if (!chk[x] || !chk[p]) continue;
            
            ans += (long long) sz[find(x)] * sz[find(p)];
            merge(x, p);
        }

        cout << ans << '\n';

        for (auto x : nodes) chk[x] = false, par[x] = 0, sz[x] = 1;
    }

    return 0;
}
