#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
#define X first
#define Y second
using namespace std;
using ll = long long;
using Point = pair<ll,ll>;

ll N, T;
unordered_set<ll> P;
unordered_map<ll, int> visited;

ll f(ll x, ll y) {
    return (x + y) * (x + y + 1) / 2 + y;
};

int BFS(Point S) {
    queue<pair<Point,int>> q;
    q.push({ S, 0 });
    visited[f(S.X, S.Y)]++;

    while (!q.empty()) {
        Point cur = q.front().X;
        int depth = q.front().Y;
        q.pop();

        ll x = cur.X, y = cur.Y;
        if (y >= T) return depth;

        for (ll dx = -2; dx <= 2; dx++) {
            for (ll dy = -2; dy <= 2; dy++) {
                ll nx = x + dx, ny = y + dy;
                if (nx < 0 || ny < 0) continue;

                ll z = f(nx, ny);
                if (P.find(z) == P.end()) continue;
                if (visited[z]++) continue;

                Point next = { nx, ny };
                q.push({ next, depth+1 });
            }
        }
    }

    return -1;
}

int main() {
    FastIO
    cin >> N >> T;

    P.insert(0);
    for (int i = 0; i < N; i++) {
        ll x, y; cin >> x >> y;
        ll z = f(x, y);
        P.insert(z);
    }

    Point S = { 0, 0 };
    int res = BFS(S);
    cout << res << '\n';

    return 0;
}
