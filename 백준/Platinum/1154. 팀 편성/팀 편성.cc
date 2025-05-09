#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int n;
bool graph[MAX][MAX];

bool vis[MAX];
bool color[MAX];
vector<int> group[2];

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

    for (int g = 0; g <= 1; g++) {
        vector<int>& team = group[g];
        int m = team.size();

        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                chk &= graph[team[i]][team[j]];
            }
        }
    }
    
    if (chk) {
        cout << 1 << '\n';

        for (int g = 0; g <= 1; g++) {
            if (!group[g].empty()) {
                sort(group[g].begin(), group[g].end());
            }

            for (int x : group[g]) {
                cout << x + 1 << ' ';
            }
            cout << -1 << '\n';
        }
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}
