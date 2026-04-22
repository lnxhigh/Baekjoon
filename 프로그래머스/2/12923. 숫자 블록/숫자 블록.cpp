#include <bits/stdc++.h>
using namespace std;

vector<int> solution(long long x, long long y) {
    vector<int> ans(y - x + 1);
    
    for (int i = 1; i <= 10000000; i++) {
        int k = (x + i - 1) / i;
        k = max(k, 2);
        
        for (int t = k; i * t <= y; t++) {
            ans[i * t - x] = i;
        }
    }
    
    return ans;
}
