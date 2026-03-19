#include <bits/stdc++.h>

using namespace std;
const int MAX = 100001;
const int MOD = 10007;

int dp[MAX][2];
bool chk[MAX][2];

int dfs(int idx, bool flag, const vector<int> &tops) {
    int n = tops.size();
    if (idx == n) return 1;
    if (chk[idx][flag]) return dp[idx][flag];
    
    int sum = 0;
    
    // 삼각형
    sum += dfs(idx + 1, false, tops);
    
    // 왼쪽 마름모
    if (!flag) sum += dfs(idx + 1, false, tops);
    
    // 오른쪽 마름모
    sum += dfs(idx + 1, true, tops);
    
    // 가운데 마름모
    if (tops[idx]) sum += dfs(idx + 1, false, tops);
    
    chk[idx][flag] = true;
    return dp[idx][flag] = sum % MOD;
}

int solution(int n, vector<int> tops) {
    return dfs(0, false, tops);
}
