#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> times, long long k) {
    int n = times.size();
    int idx = 0;
    long long limit = 0;
    vector<pair<long long, int>> vec(times.size());
    
    for (int i = 0; i < n; i++) {
        vec[i] = { times[i], i };
    }
    sort(vec.begin(), vec.end());
    
    while (idx < n and k > 0) {
        auto [t, i] = vec[idx];
        long long rest = n - idx;
        long long cnt = rest * (t - limit);
        if (k < cnt) { k %= rest; break; }
        
        k -= cnt;
        limit = t;
        while (idx < n and vec[idx].first == t) idx++;
    }
    
    vector<int> nums;
    for (int i = idx; i < n; i++) {
        nums.push_back(vec[i].second);
    }
    
    if (k >= nums.size()) return -1;
    sort(nums.begin(), nums.end());
    return nums[k] + 1;
}
