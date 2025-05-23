#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100;

int n, m, a, b;
bitset<100001> arr[MAX];

bool graph[MAX][MAX];
int pre[MAX], vis[MAX];

int main() {
    FastIO

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        for (int j = x; j <= n; j += y) arr[i][j] = 1;
    }
    cin >> a >> b;

    queue<pair<int,int>> q;
    memset(pre, -1, sizeof(pre));

    for (int i = 0; i < m; i++) {
        if (arr[i][a]) q.push({ i, 0 }), vis[i]++;

        for (int j = i + 1; j < m; j++) {
            int cnt = (arr[i] & arr[j]).count();
            if (cnt) graph[i][j] = graph[j][i] = true;
        }
    }

    int ans = 0, last = 0;
    bool chk = false;

    while (!q.empty() && !chk) {
        auto [x, cnt] = q.front();
        q.pop();
        if (arr[x][b]) ans = cnt + 1, last = x, chk = true;

        for (int nxt = 0; nxt < m; nxt++) {
            if (!graph[x][nxt]) continue;
            else if (vis[nxt]++) continue;
            
            q.push({ nxt, cnt + 1 });
            pre[nxt] = x;
        }
    }
    
    if (!chk) {
        cout << -1 << '\n';
    }
    else {
        cout << ans << '\n';
        
        stack<int> st;
        for (int i = last; i != -1; i = pre[i]) st.push(i);
        while (!st.empty()) cout << st.top() + 1 << '\n', st.pop();
    }

    return 0;
}
