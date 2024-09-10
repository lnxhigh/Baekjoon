#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N, S, D;
const int MAX = 100001;
vector<int> tree[MAX];
bool visited[MAX];
int ans = 0;

int dfs(int x) {
    visited[x] = true;
    int depth = 0;
    for (int child : tree[x]) {
        if (visited[child]) continue;
        depth = max(depth, dfs(child) + 1);
    }

    // 35% 에서 계속 틀림. why?
    if (x != S && depth >= D) ans++;
    return depth;
}

int main() {
    FastIO
    cin >> N >> S >> D; --S;
    for (int i = 0; i < N-1; i++) {
        int x, y; cin >> x >> y;
        --x; --y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    dfs(S);
    ans *= 2;
    cout << ans << '\n';
    return 0;
}
