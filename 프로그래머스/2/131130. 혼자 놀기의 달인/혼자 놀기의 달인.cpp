#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> cards) {
    int n = cards.size();
    
    vector<int> nums;
    vector<bool> vis(n);
    
    for (int &x : cards) x--;
    
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        
        int cnt = 0;
        for (int x = i; !vis[x]; x = cards[x]) {
            cnt++;
            vis[x] = true;
        }
        
        nums.push_back(cnt);
    }
    
    if (nums.size() <= 1) return 0;
    sort(nums.rbegin(), nums.rend());
    return nums[0] * nums[1];
}