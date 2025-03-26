#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const int MAX = 100001;
const ll INF = 1LL << 60;

int N, M;
vector<pair<int,int>> graph[MAX];
ll D[MAX];

ll solve() {
    fill(D + 1, D + N, INF);

    priority_queue<pair<ll,int>> pq;
    pq.push({ 0, 0 });
    
    while (!pq.empty()) {
        auto [curT, cur] = pq.top();
        curT = -curT;
        pq.pop();

        if (curT > D[cur]) continue;

        for (auto [nxt, t] : graph[cur]) {
            ll add = (t >= curT % M) ? t - curT % M : t + M - curT % M;
            ll nxtT = curT + add;

            if (nxtT < D[nxt]) {
                D[nxt] = nxtT;
                pq.push({ -nxtT, nxt });
            }
        }
    }

    return D[N - 1];
}

int main() {
    FastIO
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y; --x, --y;
        graph[x].push_back({ y, i });
        graph[y].push_back({ x, i });
    }

    ll ans = solve();
    cout << ++ans << '\n';
    return 0;
}
