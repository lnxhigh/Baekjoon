#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int v, e;
vector<int> forest[MAX];
bool vis[MAX];

void dfs(int x, int& cnt) {
    vis[x] = true;
    int deg = forest[x].size();
    if (deg & 1) cnt++;

    for (int nxt : forest[x]) {
        if (!vis[nxt]) dfs(nxt, cnt);
    }
}

int main() {
    FastIO
    cin >> v >> e;
    while (e--) {
        int x, y; cin >> x >> y;
        forest[x].push_back(y);
        forest[y].push_back(x);
    }

    int ans = 0;
    int num = 0;

    for (int i = 1; i <= v; i++) {
        if (vis[i]) continue;

        int cnt = 0;
        dfs(i, cnt);

        num++;
        ans += max(cnt - 2, 0) / 2;
    }
    
    ans += num - 1;
    cout << ans << '\n';

    return 0;
}
