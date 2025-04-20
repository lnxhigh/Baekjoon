#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100001;

int n;
int s, c, h;
vector<int> graph[MAX];

int prv[2][MAX];
bool vis[2][MAX];

set<int> cities;
int cnt[MAX];
long long ans = 0;

void dfs(int x, bool flag) {
    vis[flag][x] = true;

    for (int nxt : graph[x]) {
        if (!vis[flag][nxt]) {
            prv[flag][nxt] = x;
            dfs(nxt, flag);
        }
    }
}

int main() {
    FastIO
    cin >> n;
    cin >> s >> c >> h;

    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(s, false);
    dfs(c, true);

    vector<int> path;
    path.reserve(n << 1);

    for (int i = h; i != c; i = prv[1][i]) {
        path.push_back(i);
    }
    for (int i = c; i != s; i = prv[0][i]) {
        path.push_back(i);
    }
    path.push_back(s);

    for (int x : path) {
        cities.insert(x);
        cnt[x] = max(cnt[x], (int) cities.size() - 1); 
    }

    for (int i = 1; i <= n; i++) {
        ans += (long long) cnt[i];
    }

    cout << ans << '\n';
    return 0;
}
