#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 3001;

int N;
vector<int> graph[MAX];

bool cycle[MAX];
bool vis[MAX];

void dfs(int cur, int prv) {
    vis[cur] = true;

    for (int nxt : graph[cur]) {
        if (nxt == prv) {
            continue;
        }

        if (vis[nxt]) {
            cycle[nxt] = true;
            return;
        }
        else {
            dfs(nxt, cur);
        }
    }
}

int bfs(int x) {
    queue<pair<int,int>> q;
    q.push({ x, 0 });
    vis[x] = true;

    while (!q.empty()) {
        auto [cur, level] = q.front();
        q.pop();
        if (cycle[cur]) return level;

        for (int nxt : graph[cur]) {
            if (vis[nxt]) continue;
            q.push({ nxt, level + 1 });
            vis[nxt] = true;
        }
    }

    return 0;
}

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        graph[x].push_back(y);
        graph[y].push_back(x);        
    }

    for (int i = 0; i < N; i++) {
        memset(vis, false, sizeof(vis));
        dfs(i, -1);
    }

    for (int i = 0; i < N; i++) {
        memset(vis, false, sizeof(vis));
        cout << bfs(i) << ' ';
    }
    cout << '\n';

    return 0;
}
