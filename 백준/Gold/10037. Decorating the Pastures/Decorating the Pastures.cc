#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 50001;

int n, m;
vector<int> graph[MAX];
int vis[MAX];

bool dfs(int x, int t, int cnt[2]) {
    vis[x] = t;
    cnt[t & 1]++;

    for (int nxt : graph[x]) {
        if (vis[nxt]) {
            if ((vis[nxt] & 1) == (t & 1)) {
                return false;
            }
        }
        else  {
            if (!dfs(nxt, t + 1, cnt)) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    FastIO
    cin >> n >> m;

    while (m--) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int ans = 0;
    bool chk = true;

    for (int i = 1; i <= n && chk; i++) {
        if (vis[i]) continue;

        int cnt[2] = { 0, 0 };
        if (!dfs(i, 1, cnt)) chk = false;
        ans += max(cnt[0], cnt[1]);
    }

    if (!chk) ans = -1;
    cout << ans << '\n';

    return 0;
}
