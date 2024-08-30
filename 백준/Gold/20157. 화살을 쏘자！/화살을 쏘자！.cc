#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

// 직선이 아니라 반직선 그어야 됨 ...

int N;
unordered_map<ll,int> score;

auto f = [] (ll x, ll y) {
    const int offset = 1 << 20;
    x += offset; y += offset;
    return (x + y) * (x + y + 1) / 2 + y; 
};

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll x, y; cin >> x >> y;
        ll d = __gcd(x, y);
        x /= abs(d); y /= abs(d);
        score[f(x, y)]++;
    }

    int res = 0;
    for (auto p : score) { res = max(res, p.second); }
    cout << res << '\n';
    return 0;
}
