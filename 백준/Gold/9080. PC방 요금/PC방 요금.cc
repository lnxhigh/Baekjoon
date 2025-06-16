#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int startTime;
int duration;
int dp[4321];

int f(int t) {
    t %= 60 * 24;
    if (t >= 60 * 22) return (60 * 24) - t + 60 * 8;
    else if (t < 60 * 8) return (60 * 8) - t;
    return 0;
}

int dfs(int t) {
    if (t >= duration) return 0;
    int& ret = dp[t];
    if (ret) return ret;

    ret = 1000 + dfs(t + 60);
    int add = f(startTime + t);
    if (add > 0) ret = min(ret, 5000 + dfs(t + add));

    return ret;
}

int main() {
    FastIO
    
    int tc; cin >> tc;
    while (tc--) {
        string str; cin >> str;
        cin >> duration;

        int h = stoi(str.substr(0, 2));
        int m = stoi(str.substr(3, 2));
        startTime = 60 * h + m;

        memset(dp, 0, sizeof(dp));
        int ans = dfs(0);
        cout << ans << '\n';
    }

    return 0;
}
