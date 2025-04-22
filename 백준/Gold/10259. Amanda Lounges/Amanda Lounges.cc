#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 200001;

int n, m;
vector<pair<int,int>> graph[MAX];
bool states[2][MAX];
bool vis[2][MAX];

bool dfs(int x, bool flag, int& cnt, bool state[MAX], bool visited[MAX]) {
    bool ret = true;
    state[x] = flag;
    visited[x] = true;
    
    if (flag) cnt++;

    for (auto [nxt, c] : graph[x]) {
        if ((c == 0 && flag) || (c == 2 && !flag)) ret = false;
        bool nxt_flag = (c == 0) ? false : (c == 2) ? true : !flag;

        if (visited[nxt]) {
            if (state[nxt] != nxt_flag) ret = false;
        }
        else {
            if (!dfs(nxt, nxt_flag, cnt, state, visited)) ret = false;
        }
    }

    return ret;
}

int main() {
    FastIO
    cin >> n >> m;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        --a, --b;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    int ans = 0;

    for (int i = 0; i < n && ans >= 0; i++) {
        if (vis[0][i] || vis[1][i]) continue;

        int x = 0, y = 0;

        if (!vis[0][i]) {
            bool chk = dfs(i, false, x, states[0], vis[0]);
            if (!chk) x = -1;
        }
        if (!vis[1][i]) {
            bool chk = dfs(i, true, y, states[1], vis[1]);
            if (!chk) y = -1;
        }
        
        if (x < 0 && y < 0) ans = -1;
        else if (x < 0) ans += y;
        else if (y < 0) ans += x;
        else ans += min(x, y);
    }

    if (ans < 0) cout << "impossible" << '\n';
    else cout << ans << '\n';

    return 0;
}
