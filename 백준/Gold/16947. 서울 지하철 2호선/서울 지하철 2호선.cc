#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 3001;

int N;
vector<int> graph[MAX];
int par[MAX], deg[MAX], dst[MAX];

int dfs(int x) {
    if (deg[x]) return 0;
    else if (dst[x]) return dst[x];
    return dst[x] = dfs(par[x]) + 1;
}

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y; --x, --y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        deg[x]++, deg[y]++;
    }

    queue<int> q;
    memset(par, -1, sizeof(par));
    for (int i = 0; i < N; i++) {
        if (deg[i] <= 1) q.push(i);
    }
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int nxt : graph[cur]) {
            if (deg[nxt] == 0) continue;
            par[cur] = nxt;
            --deg[cur], --deg[nxt];
            if (deg[nxt] <= 1) q.push(nxt);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << dfs(i) << ' ';
    }
    cout << '\n';
    return 0;
}
