#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int n;
bool graph[MAX][MAX];

bool vis[MAX];
bool color[MAX];
vector<int> group[2];

void print(vector<int>& vec) {
    if (!vec.empty()) sort(vec.begin(), vec.end());
    for (int x : vec) cout << x + 1 << ' ';
    cout << -1 << '\n';
}

bool dfs(int x, bool flag) {
    bool ret = true;
    vis[x] = true;
    color[x] = flag;
    group[flag].emplace_back(x);

    for (int nxt = 0; nxt < n; nxt++) {
        if (nxt == x || graph[x][nxt]) continue;
        ret &= vis[nxt] ? (color[x] != color[nxt]) : dfs(nxt, !flag);
    }

    return ret;
}

int main() {
    FastIO

    cin >> n;
    while (true) {
        int x, y; cin >> x >> y;
        if (x < 0 || y < 0) break;

        --x, --y;
        graph[x][y] = graph[y][x] = true;
    }

    bool chk = true;

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        chk &= dfs(i, false);
    }

    // The complement of a bipartite graph is perfect

    int ans = chk ? 1 : -1;
    cout << ans << '\n';
    if (chk) print(group[0]), print(group[1]);

    return 0;
}
