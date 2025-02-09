#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const int MAX = 300001;

int N;
vector<pair<int,ll>> tree[MAX];

int par[MAX], weight[MAX];
ll treesize[MAX], sum[MAX];
ll res[MAX];

void init(int cur, int prv) {
    for (auto [nxt, w] : tree[cur]) {
        if (nxt == prv) continue;
        
        par[nxt] = cur;
        weight[nxt] = w;
        init(nxt, cur);
    }
}

ll get_sum(int x) {
    if (x < 0) return 0;
    else if (sum[x] != -1) return sum[x];
    return sum[x] = get_sum(par[x]) + weight[x];
}

ll get_treesize(int x) {
    if (treesize[x] != -1) return treesize[x];
    
    ll cnt = 0;
    for (auto [nxt, w] : tree[x]) {
        if (nxt == par[x]) continue;
        cnt += get_treesize(nxt);
    }

    return treesize[x] = ++cnt;
}

void solve(int x, ll val) {
    res[x] = val;
    for (auto [nxt, w] : tree[x]) {
        if (nxt == par[x]) continue;
        int one = get_treesize(nxt);
        int other = N - one;
        solve(nxt, val + w * (other - one));
    }
}

int main() {
    FastIO
    cin >> N;
    for (int i = 1; i < N; i++) {
        int u, v, d;
        cin >> u >> v >> d; --u, --v;
        tree[u].push_back({ v, d });
        tree[v].push_back({ u, d });
    }

    memset(sum, -1, sizeof(sum));
    memset(treesize, -1, sizeof(treesize));

    par[0] = -1;
    weight[0] = 0;
    init(0, -1);

    ll val = 0;
    for (int i = 0; i < N; i++) {
        val += get_sum(i);
    }

    solve(0, val);
    for (int i = 0; i < N; i++) {
        cout << res[i] << '\n';
    }

    return 0;
}
