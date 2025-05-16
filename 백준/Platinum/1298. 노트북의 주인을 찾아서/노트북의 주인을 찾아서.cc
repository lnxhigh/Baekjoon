#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 101;

int n, m;
vector<int> graph[MAX];
int one[MAX], other[MAX];
int vis[MAX];

bool dfs(int x, int t){
    vis[x] = t;
    for (int nxt : graph[x]) {
        int y = other[nxt];
        if (y == 0 || ((vis[y] != t) && dfs(y, t))) {
            one[x] = nxt, other[nxt] = x;
            return true;
        }
    }

    return false;
}

int main() {
    FastIO

    cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        graph[a].emplace_back(b);
    }
    
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (!one[i]) {
            if (dfs(i, i)) ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
