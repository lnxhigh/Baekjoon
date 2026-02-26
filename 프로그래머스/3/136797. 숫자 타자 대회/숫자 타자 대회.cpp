#include <bits/stdc++.h>

using namespace std;

int dist[10][10] = {
    { 1, 7, 6, 7, 5, 4, 5, 3, 2, 3 },
    { 7, 1, 2, 4, 2, 3, 5, 4, 5, 6 },
    { 6, 2, 1, 2, 3, 2, 3, 5, 4, 5 },
    { 7, 4, 2, 1, 5, 3, 2, 6, 5, 4 },
    { 5, 2, 3, 5, 1, 2, 4, 2, 3, 5 },
    { 4, 3, 2, 3, 2, 1, 2, 3, 2, 3 },
    { 5, 5, 3, 2, 4, 2, 1, 5, 3, 2 },
    { 3, 4, 5, 6, 2, 3, 5, 1, 2, 4 },
    { 2, 5, 4, 5, 3, 2, 3, 2, 1, 2 },
    { 3, 6, 5, 4, 5, 3, 2, 4, 2, 1 },
};

const int MAX = 100001;
const int INF = 1000 * 1000 * 1000;

int dp[MAX][10][10];

int dfs(int idx, int l, int r, string &nums) { 
    if (idx >= nums.size()) return 0;
    if (dp[idx][l][r]) return dp[idx][l][r];
    int t = nums[idx] - '0';
    
    // Same
    if (l == t || r == t) {
        return dp[idx][l][r] = dfs(idx + 1, l, r, nums) + 1;
    }
    
    // Left / Right
    int x = dfs(idx + 1, t, r, nums) + dist[l][t];
    int y = dfs(idx + 1, l, t, nums) + dist[r][t];
    return dp[idx][l][r] = min(x, y);
}

int solution(string nums) {
    int n = nums.size();
    int ans = dfs(0, 4, 6, nums);
    return ans;
}
