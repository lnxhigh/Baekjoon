#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;

int64 dfs(int64 idx, int64 value, const vector<pair<int64,bool>> &Coin) {
    if (value == 0 || idx < 0) return 0;
    const auto& [x, flag] = Coin[idx];
    
    int64 cnt = value / x;
    int64 first = cnt + dfs(idx - 1, value - cnt * x, Coin);
    if (!flag || !cnt) return first;

    int64 second = (cnt - 1) + dfs(idx - 1, value - (cnt - 1) * x, Coin);
    return min(first, second);
}

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int64 X; cin >> X;
        vector<pair<int64,bool>> Coin;
        for (int64 i = 1 ; i <= X; i *= 10 ) Coin.push_back({ i, false });
        for (int64 i = 25; i <= X; i *= 100) Coin.push_back({ i, true  });
        sort(Coin.begin(), Coin.end());

        int64 L = Coin.size();
        int64 ans = dfs(L - 1, X, Coin);
        cout << ans << '\n';
    }
    
    return 0;
}
