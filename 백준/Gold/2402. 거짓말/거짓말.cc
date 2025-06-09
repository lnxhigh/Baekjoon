#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 10001;

int n, m;
vector<tuple<int,int,bool>> query;

map<int,int> cache;
vector<vector<pair<int,bool>>> graph;

bool res[MAX];
int vis[MAX];

void dfs(int x, bool chk, int t) {
    res[x] = chk, vis[x] = t;
    for (auto [nxt, flag] : graph[x]) {
        if (vis[nxt] != t) dfs(nxt, chk ^ flag, t);
    }
}

int main() {
    FastIO

    cin >> n >> m;
    query.resize(m);

    int cnt = 0;
    for (auto& [x, y, f] : query) {
        cin >> x >> y >> f, x--;
        if (!cache.count(x)) cache[x] = cnt++;
        if (!cache.count(y)) cache[y] = cnt++;
    }

    int ans = m;
    graph.resize(cnt);

    for (int i = 0; i < m && ans == m; i++) {
        auto [x, y, f] = query[i];
        x = cache[x], y = cache[y];

        dfs(x, false, i + 1);
        bool cycle = (vis[y] == i + 1);

        if (cycle) {
            if (res[y] ^ f) ans = i;
        }
        else {
            graph[x].emplace_back(y, f);
            graph[y].emplace_back(x, f);
        }
    }

    cout << ++ans << '\n';
    return 0;
}
