#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const ll MAX = 100001;
const ll MOD = 1'000'000'007;

ll N;
vector<pair<int,ll>> graph[MAX], tree[MAX];
ll P[MAX], D[MAX];

void init(int cur, int prv) {
    for (auto [nxt, weight] : graph[cur]) {
        if (nxt == prv) continue;

        tree[cur].push_back({ nxt, weight });
        init(nxt, cur);
    }
}

ll f(int x) {
    if (P[x] != -1) return P[x];
    
    ll ret = 1;
    for (auto [nxt, weight] : tree[x]) {
        ret += f(nxt) * weight % MOD;
        ret %= MOD;
    }

    return P[x] = ret;
}

ll dfs(int x) {
    if (D[x] != -1) return D[x];

    // 1. Intra
    ll intra = 0;
    for (auto [nxt, weight] : tree[x]) {
        intra = (intra + dfs(nxt)) % MOD;
    }

    // 2. Inter
    ll inter = 0;
    ll sum = 0, sq = 0;

    for (auto [nxt, weight] : tree[x]) {
        ll val = f(nxt) * weight % MOD;
        sum = (sum + val) % MOD;
        sq = (sq + val * val) % MOD;
    }
    
    inter = ((sum * sum) + (MOD - sq)) % MOD;
    inter = (inter * ((MOD + 1) / 2)) % MOD; // Divide by 2

    // 3. Root
    ll root = f(x) + (MOD - 1);

    return D[x] = (root + intra + inter) % MOD;
}

int main() {
    FastIO
    cin >> N;
    for (int i = 1; i < N; i++) {
        int A, B; cin >> A >> B;
        ll W; cin >> W;

        graph[A].push_back({ B, W });
        graph[B].push_back({ A, W });
    }

    memset(P, -1, sizeof(P));
    memset(D, -1, sizeof(D));

    init(1, 0);
    cout << dfs(1) << '\n';
    return 0;
}
