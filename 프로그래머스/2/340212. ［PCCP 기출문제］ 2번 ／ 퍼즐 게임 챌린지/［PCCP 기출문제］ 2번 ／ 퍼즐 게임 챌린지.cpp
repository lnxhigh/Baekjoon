#include <bits/stdc++.h>

using namespace std;

bool check(int x, vector<int> &diffs, vector<int> &times, long long limit) {
    long long sum = times[0];
    int len = diffs.size();
    
    for (int i = 1; i < len; i++) {
        long long effort = times[i];
        int trial = max(diffs[i] - x, 0);
        effort += (long long) trial * (times[i] + times[i - 1]);
        
        sum += effort;
        if (sum > limit) return false;
    }
    
    return sum <= limit;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int ans = 0;
    
    int low = 1;
    int high = *max_element(diffs.begin(), diffs.end());
    
    while (low <= high) {
        int mid = (low + high) / 2;
        bool flag = check(mid, diffs, times, limit);
        
        if (flag) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return ans;
}