#include <bits/stdc++.h>

using namespace std;
const int INF = 1024 * 1024;

int dp[1024][2048];
bool chk[1024][2048];

int sign(int x) {
    if (x == 0) return 0;
    return x / abs(x);
}

int dfs(int idx, int x, 
    int t, int t_min, int t_max, int a, int b, const vector<int> &onboard
) {
    if (idx >= onboard.size()) return 0;
    if (onboard[idx] && (x < t_min || x > t_max)) return INF;
    if (chk[idx][x]) return dp[idx][x];
    
    int res = INF;
    
    // on
    int on = dfs(idx + 1, x, t, t_min, t_max, a, b, onboard) + b;
    on = min(on, dfs(idx + 1, x + 1, t, t_min, t_max, a, b, onboard) + a);
    on = min(on, dfs(idx + 1, x - 1, t, t_min, t_max, a, b, onboard) + a);
    
    // off
    int off = dfs(idx + 1, x + sign(t - x), t, t_min, t_max, a, b, onboard);

    chk[idx][x] = true;
    return dp[idx][x] = min(on, off);
}

int solution(int t, int t_min, int t_max, int a, int b, vector<int> onboard) {
    int offset = 1024;
    t += offset, t_min += offset, t_max += offset;
    return dfs(0, t, t, t_min, t_max, a, b, onboard);
}
