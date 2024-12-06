#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
int64 N, K, Q;

int64 dist(int64 u, int64 v) {
    if (K == 1) return abs(u - v);

    stack<int64> x, y;
    for (int64 i = u; i; i = (i - 1) / K) x.push(i);
    for (int64 i = v; i; i = (i - 1) / K) y.push(i);
    while (!x.empty() && !y.empty()) {
        if (x.top() != y.top()) break;
        x.pop(), y.pop();
    }

    return x.size() + y.size();
}

int main() {
    FastIO
    cin >> N >> K >> Q;
    while (Q--) {
        int64 x, y; cin >> x >> y; --x, --y;
        cout << dist(x, y) << '\n';
    }
    return 0;
}
