#include <bits/stdc++.h>
using namespace std;
const int MAX = 5000001;

int arr[MAX];
int dp[MAX];

vector<int> solution(int x, vector<int> nums) {
    for (int i = 1; i <= x; i++) {
        for (int j = i; j <= x; j += i) {
            arr[j]++;
        }
    }
    
    int m = x;
    dp[x] = x;
    
    for (int i = x - 1; i >= 1; i--) {
        if (arr[i] >= arr[m]) {
            m = i;
            dp[i] = i;
        } else {
            dp[i] = dp[i + 1];
        }
    }
    
    int n = nums.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = dp[nums[i]];
    }
    
    return ans;
}
