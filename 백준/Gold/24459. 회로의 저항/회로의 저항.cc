#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100005;

int N;
vector<pair<int,int>> graph[MAX];
vector<pair<int,int>> tree[MAX];

int P[MAX], W[MAX];
int H[MAX], X[MAX], Y[MAX];

void input() {
    cin >> N;
    for (int i = 1; i < N; i++) {
        int p, q, w; cin >> p >> q >> w;
        graph[p].push_back({ q, w });
        graph[q].push_back({ p, w });
    }
}

void init(int cur, int prv) {
    for (const auto& [nxt, weight] : graph[cur]) {
        if (nxt == prv) continue;
        tree[cur].push_back({ nxt, weight });
        P[nxt] = cur, W[nxt] = weight;
        init(nxt, cur);
    }
}

int f(int x) {
    if (x == 0) return 0;
    else if (H[x]) return H[x];
    return H[x] = f(P[x]) + W[x];
}

int dfsmin(int cur) {
    if (tree[cur].empty()) return 0;
    else if (X[cur]) return X[cur];

    int ret = 1 << 30;
    for (auto [nxt, weight] : tree[cur]) {
        ret = min(ret, dfsmin(nxt) + weight);
    }

    return X[cur] = ret;
}

int dfsmax(int cur) {
    if (tree[cur].empty()) return 0;
    else if (Y[cur]) return Y[cur];

    int ret = 0;
    for (auto [nxt, weight] : tree[cur]) {
        ret = max(ret, dfsmax(nxt) + weight);
    }
    
    return Y[cur] = ret;
}

pair<int,int> solve() {
    int low = 1 << 30, high = 0;
    for (int cur = 0; cur < N; cur++) {
        if ((int) tree[cur].size() <= 1) continue;
        
        vector<int> lows, highs;
        for (auto [nxt, weight] : tree[cur]) {
            lows.push_back(dfsmin(nxt) + weight);
            highs.push_back(dfsmax(nxt) + weight);
        }

        sort(lows.begin(), lows.end());
        sort(highs.begin(), highs.end(), [] (int& x, int& y) { return x > y; });

        low = min(low, lows[0] + lows[1]);
        high = max(high, highs[0] + highs[1]);
    }

    if ((int) tree[0].size() == 1) {
        for (int i = 1; i < N; i++) {
            if (tree[i].empty()) {
                low  = min(low,  f(i));
                high = max(high, f(i));
            }
        }
    }

    return { low, high };
}

int main() {
    FastIO
    input();
    init(0, -1);
    auto [low, high] = solve();
    cout << high << '\n' << low << '\n';
    return 0;
}
