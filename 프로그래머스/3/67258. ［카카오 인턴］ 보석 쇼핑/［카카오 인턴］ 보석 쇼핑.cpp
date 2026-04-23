#include <bits/stdc++.h>
using namespace std;

pair<int,int> f(int x, const vector<int> &nums) {
    int n = nums.size();
    if (n < x) return { 0, 0 };
    
    int size = 0;
    vector<int> counts(n);
    
    for (int i = 0; i < x; i++) {
        int num = nums[i];
        if (counts[num]++ == 0) size++;
    }
    
    int idx = 0;
    int cnt = size;
    
    for (int i = 0; i < n - x; i++) {
        int new_num = nums[x + i];
        int old_num = nums[i];
        if (new_num == old_num) continue;
        
        if (counts[new_num]++ == 0) size++;
        if (--counts[old_num] == 0) size--;
        
        if (size > cnt) idx = i + 1, cnt = size;
    }
    
    return { idx, cnt };
}

vector<int> solution(vector<string> gems) {
    int n = gems.size();
    int k = 0;
    unordered_map<string,int> idx_map;
    unordered_map<string,bool> vis;
    
    for (const string &gem : gems) {
        if (vis[gem]) continue;
        vis[gem] = true;
        idx_map[gem] = k++;
    }
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        nums[i] = idx_map[gems[i]];
    }
    
    int low = 1, high = n;
    int s = 0, e = n - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        auto [idx, cnt] = f(mid, nums);
        bool chk = (cnt == k);
        
        if (chk) high = mid - 1, s = idx + 1, e = idx + mid;
        else low = mid + 1;
    }

    return { s, e };
}
