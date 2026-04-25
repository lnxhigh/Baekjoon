#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using user = tuple<int,int,int>;

int k, n, c;
vector<user> x, y;

int solve(vector<user>& arr) {
    int ret = 0;
    vector<int> cur(n);
    sort(arr.begin(), arr.end());

    for (auto [e, s, m] : arr) {
        int add = c;
        for (int i = s; i < e && add > 0; i++) {
            add = min(add, min(m, c - cur[i]));
        }
        if (add <= 0) continue;

        ret += add;
        for (int i = s; i < e; i++) {
            cur[i] += add;
        }
    }

    return ret;
}

int main() {
    FastIO
    cin >> k >> n >> c;

    for (int i = 0; i < k; i++) {
        int s, e, m; cin >> s >> e >> m; --s, --e;
        if (s < e) x.emplace_back(e, s, m);
        else y.emplace_back(n - 1 - e, n - 1 - s, m);
    }
    
    int ans = solve(x) + solve(y);
    cout << ans << '\n';

    return 0;
}
