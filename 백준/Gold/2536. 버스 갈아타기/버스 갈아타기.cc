#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
using Point = pair<int,int>;
using Line = pair<Point,Point>;
const int MAX = 5005;

int M, N, K;
Line Data[MAX];
bool vis[MAX];

void input() {
    cin >> M >> N >> K;

    for (int i = 1; i <= K; i++) {
        int b, x1, y1_, x2, y2;
        cin >> b >> x1 >> y1_ >> x2 >> y2;
        Point p = { x1, y1_ }, q = { x2, y2 };
        if (p > q) swap(p, q);
        Data[i] = { p, q };
    }
    
    int sx, sy, dx, dy;
    cin >> sx >> sy >> dx >> dy;
    Point src = { sx, sy }, dst = { dx, dy };
    
    Data[0] = { src, src };
    Data[K + 1] = { dst, dst };
}

int ccw(Point &a, Point &b, Point &c) {
    ll x1 = a.first - b.first;
    ll y1_ = a.second - b.second;
    ll x2 = a.first - c.first;
    ll y2 = a.second - c.second;

    ll det = x1 * y2 - x2 * y1_;
    if (det) det /= abs(det);
    return det;
}

bool cross(Line &p, Line &q) {
    auto [a, b] = p;
    auto [c, d] = q;

    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);

    if (ab == 0 && cd == 0) {
        return max(a, c) <= min(b, d);
    }
    return ab <= 0 && cd <= 0;
}

int bfs() {
    queue<pair<int,int>> q;
    q.push({ 0, 0 });
    vis[0] = true;

    while (!q.empty()) {
        auto [cur, cnt] = q.front();
        q.pop();

        if (cur == K + 1) return --cnt;

        for (int nxt = 1; nxt <= K + 1; nxt++) {
            if (vis[nxt]) continue;
            if (!cross(Data[cur], Data[nxt])) continue;

            q.push({ nxt, cnt + 1 });
            vis[nxt] = true;
        }
    }

    return -1;
}

int main() {
    FastIO
    input();
    int ans = bfs();
    cout << ans << '\n';

    return 0;
}
