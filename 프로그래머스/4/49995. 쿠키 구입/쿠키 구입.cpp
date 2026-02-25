#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums) {
    int n = nums.size();
    int ans = 0;
    
    for (int m = 0; m < n - 1; m++) {
        int l = m, r = m + 1;
        int lsum = nums[l], rsum = nums[r];
        
        while (l >= 0 && r < n) {
            if (lsum < rsum) {
                if (l == 0) break;
                lsum += nums[--l];
            } else if (lsum > rsum) {
                if (r == n - 1) break;
                rsum += nums[++r];
            } else {
                ans = max(ans, lsum + rsum >> 1);
                if (l == 0 || r == n - 1) break;
                lsum += nums[--l], rsum += nums[++r];
            }
        }
    }
    
    return ans;
}
