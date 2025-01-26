#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
using Edge = pair<int64,int64>;

int64 N;
vector<vector<Edge>> tree;
vector<int64> D;

int64 dfs(int64 cur, int64 prv) {
    for (auto [nxt, weight] : tree[cur]) {
        if (nxt == prv) continue;
        D[cur] += dfs(nxt, cur);
    }

    return ++D[cur];
}

int64 sum(int64 cur, int64 prv) {
    int64 ret = 0;
    for (auto [nxt, weight] : tree[cur]) {
        if (nxt == prv) continue;
        ret += sum(nxt, cur) + D[nxt] * weight;
    }
    return ret;
}

void solve(int64 cur, int64 prv, int64 val, int64 &ans) {
    ans = min(ans, val);
    for (auto [nxt, weight] : tree[cur]) {
        if (nxt == prv) continue;
        int64 one = D[nxt];
        int64 other = N - one;
        int64 delta = weight * (other - one);
        solve(nxt, cur, val + delta, ans);
    }
}

int main() {
    FastIO
    while (true) {
        cin >> N;
        if (N == 0) break;
        
        tree.resize(N);
        D.resize(N);
        
        for (int64 i = 1; i < N; i++) {
            int64 a, b, w; cin >> a >> b >> w;
            tree[a].push_back({ b, w });
            tree[b].push_back({ a, w });
        }

        dfs(0, -1);
        
        int64 val = sum(0, -1);
        int64 ans = val;
        solve(0, -1, val, ans);
        
        cout << ans << '\n';
        tree.clear();
        D.clear();
    }

    return 0;
}
