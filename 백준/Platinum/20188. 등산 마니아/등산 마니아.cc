#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int MAX = 300001;

int N;
vector<int> graph[MAX];
vector<int> tree[MAX];

int64 S[MAX], W[MAX], D[MAX];

void init(int cur, int prv) {
    for (int nxt : graph[cur]) {
        if (nxt == prv) continue;
        tree[cur].push_back(nxt);
        init(nxt, cur);
    }
}

int64 size(int x) {
    if (S[x]) return S[x];
    int64 cnt = 0;
    for (int nxt : tree[x]) {
        cnt += size(nxt);
    }
    return S[x] = ++cnt;
}

int64 sum(int x) {
    if (W[x]) return W[x];
    int64 ret = 0;
    for (int nxt : tree[x]) {
        ret += sum(nxt) + size(nxt);
    }
    return W[x] = ret;
}

int64 dfs(int x) {
    if (D[x]) return D[x];

    int64 cnt = 0;
    for (int nxt : tree[x]) {
        int64 one = size(nxt);
        int64 other = size(x) - size(nxt);
        cnt += dfs(nxt) + (one * (one - 1) / 2);
        cnt += (sum(nxt) + one) * other;
    }

    return D[x] = cnt;
}

int main() {
    FastIO
    cin >> N;
    for (int i = 1; i < N; i++) {
        int x, y; cin >> x >> y; --x, --y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    init(0, -1);
    int64 ans = dfs(0);
    cout << ans << '\n';
    return 0;
}
