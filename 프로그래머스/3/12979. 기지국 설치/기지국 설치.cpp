#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> nums, int w) {
    int x = 0;
    int ans = 0;
    
    for (int num : nums) {
        int y = num - w - 1;
        int len = y - x;
        
        if (len <= 0) {
            int nxt = max(x, num + w);
            x = nxt;
        } else {
            int r = 2 * w + 1; 
            int cnt = (len + r - 1) / r;
            int nxt = max(x + r * cnt, num + w);
            x = nxt;
            ans += cnt;
        }
    }
    
    if (x < n) {
        int len = n - x;
        int r = 2 * w + 1;
        int cnt = (len + r - 1) / r;
        ans += cnt;
    }
    
    return ans;
}