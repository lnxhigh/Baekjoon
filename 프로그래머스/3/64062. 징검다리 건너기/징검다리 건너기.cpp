#include <string>
#include <vector>

using namespace std;

bool check(int x, int k, const vector<int> &stones) {
    int n = stones.size();
    vector<int> vec(stones.begin(), stones.end());
    for (int &num : vec) num -= x;
    
    int diff = 0;
    int from = -1, idx = 0;
    
    while (idx < n) {
        while (idx < n && vec[idx] <= 0) idx++;
        int to = idx;
        diff = max(diff, to - from);
        
        from = to;
        idx++;
    }
    
    return diff <= k;
}

int solution(vector<int> stones, int k) {
    int ans = 0;
    int low = 1, high = 200000000;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid, k, stones)) ans = mid, low = mid + 1;
        else high = mid - 1;
    }
    
    ans++;
    return ans;
}