#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 3001;

int N;
vector<int> graph[MAX];

bool finish;
bool cycle[MAX];
int par[MAX];
bool vis[MAX];
int dst[MAX];

void dfs(int cur, int prv) {
    vis[cur] = true;
    par[cur] = prv;

    for (int nxt : graph[cur]) {
        if (finish) return;
        else if (nxt == par[cur]) continue;

        if (vis[nxt]) {
            finish = true;
            for (int x = cur; x != nxt; x = par[x]) {
                cycle[x] = true;
            }
            cycle[nxt] = true;
        }
        else {
            dfs(nxt, cur);
        }
    }
}

void perf(int cur, int val) {
    vis[cur] = true;
    dst[cur] = val;

    for (int nxt : graph[cur]) {
        if (vis[nxt] || cycle[nxt]) continue;
        perf(nxt, val + 1);
    }
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

    dfs(0, -1);

    memset(vis, false, sizeof(vis));
    for (int i = 0; i < N; i++) {
        if (cycle[i] && graph[i].size() > 2u) {
            perf(i, 0);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << dst[i] << ' ';
    }
    cout << '\n';
    return 0;
}
