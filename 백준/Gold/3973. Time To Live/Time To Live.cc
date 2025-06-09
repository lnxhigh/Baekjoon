#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> tree(n);
        queue<int> q;
        vector<int> deg(n);
        vector<bool> vis(n);

        for (int i = 1; i < n; i++) {
            int x, y; cin >> x >> y;
            tree[x].emplace_back(y);
            tree[y].emplace_back(x);
            deg[x]++, deg[y]++;
        }

        int center = 0;

        for (int i = 0; i < n; i++) {
            if (deg[i] == 1) q.push(i);
        }

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            center = x;

            for (int nxt : tree[x]) {
                deg[x]--, deg[nxt]--;
                if (deg[nxt] == 1) q.push(nxt);
            }
        }

        int ans = 0;

        q.push(center);
        vis[center] = true;

        while (!q.empty()) {
            ans++;
            int len = q.size();

            for (int i = 0; i < len; i++) {
                int x = q.front();
                q.pop();

                for (int nxt : tree[x]) {
                    if (!vis[nxt]) q.push(nxt), vis[nxt] = true;
                }
            }
        }
        
        cout << --ans << '\n';
    }

    return 0;
}
