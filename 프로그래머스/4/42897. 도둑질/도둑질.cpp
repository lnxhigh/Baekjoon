#include <bits/stdc++.h>
using namespace std;

const int MAX = 1 << 20;
int dp[MAX][2][2];

int solution(vector<int> arr) {
    int n = arr.size();

    dp[1][0][0] = 0;
    dp[1][0][1] = arr[1];
    dp[1][1][0] = arr[0];
    
    for (int x = 2; x < n; x++) {
        dp[x][0][0] = max(dp[x - 1][0][0], dp[x - 1][0][1]);
        dp[x][0][1] = dp[x - 1][0][0] + arr[x];
        dp[x][1][0] = max(dp[x - 1][1][0], dp[x - 1][1][1]);
        dp[x][1][1] = dp[x - 1][1][0] + arr[x];
    }
    
    int ans = max(dp[n - 1][0][1], dp[n - 1][1][0]);
    ans = max(ans, dp[n - 1][0][0]);
    return ans;
}
