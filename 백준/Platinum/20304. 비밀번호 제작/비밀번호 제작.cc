#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100'000;

int n, m;
int p = 0;

queue<pair<int,int>> q;
bool vis[1 << 20];
int ans = 0;

int main() {
    FastIO

    cin >> n >> m;
    while (m--) {
        cin >> p;
        q.push({ p, 0 });
        vis[p] = true;
    }

    while (!q.empty()) {
        auto [x, cnt] = q.front();
        q.pop();
        
        ans = max(ans, cnt);

        for (int i = 0; i < 20; i++) {
            int nxt = x ^ (1 << i);
            if (nxt <= n && !vis[nxt]) {
                q.push({ nxt, cnt + 1 });
                vis[nxt] = true;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
