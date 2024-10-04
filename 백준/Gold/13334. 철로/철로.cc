#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;

int main() {
    FastIO

    int N; cin >> N;
    vector<pair<int64,int64>> __V(N);
    for (auto &[h, o] : __V) {
        int64 x, y; cin >> x >> y;
        h = min(x, y), o = max(x, y);
    }
    int64 d; cin >> d;

    vector<pair<int64,int64>> V;
    for (auto &[h, o] : __V) {
        if (o - h <= d) V.push_back({ h, o });
    }
    
    N = (int) V.size();
    sort(V.begin(), V.end());

    priority_queue<int64,vector<int64>,greater<int64>> pq;
    for (auto &[h, o] : V) pq.push(o);

    int res = 0;

    for (int i = 0; i < N; i++) {
        auto [h, o] = V[i];
        while (!pq.empty() && pq.top() <= h + d) pq.pop();
        res = max(res, N - i - (int) pq.size());
    }

    cout << res << '\n';
    return 0;
}
