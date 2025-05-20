#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int vis[101][20001];

int main() {
    FastIO
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        memset(vis, -1, sizeof(vis));

        queue<pair<int,int>> q;
        q.push({ 1, 1 % n });
        vis[1][1 % n] = 0;

        int x = -1;

        while (!q.empty()) {
            auto [cnt, r] = q.front();
            q.pop();

            if (r == 0) { x = cnt; break; }

            int a = (10 * r) % n;
            int b = (10 * r + 1) % n;
            cnt++;

            if (cnt <= 100 && vis[cnt][a] == -1) q.push({ cnt, a }), vis[cnt][a] = r;
            if (cnt <= 100 && vis[cnt][b] == -1) q.push({ cnt, b }), vis[cnt][b] = r;
        }

        if (x == -1) {
            cout << "BRAK" << '\n';
        }
        else {
            int r = 0;
            vector<int> path;

            for (int i = x; i > 0; i--) {
                path.push_back(r);
                r = vis[i][r];
            }
            path.push_back(0);

            reverse(path.begin(), path.end());

            for (int i = 1; i < path.size(); i++) {
                int x = path[i - 1], y = path[i];
                bool flag = (y == (10 * x + 1) % n);
                cout << flag;
            }
            
            cout << '\n';
        }
    }

    return 0;
}
