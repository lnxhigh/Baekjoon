#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> signals) {
    int n = signals.size();
    vector<int> sums(n);
    
    int ans = -1;
    int mul = 1;
    
    for (int i = 0; i < n; i++) {
        const vector<int> &signal = signals[i];
        int g = signal[0], y = signal[1], r = signal[2];
        int sum = g + y + r;
        
        sums[i] = sum;
        mul *= sum;
    }
    
    for (int t = 1; t <= mul; t++) {
        bool chk = true;
        for (int i = 0; i < n && chk; i++) {
            const vector<int> &signal = signals[i];
            int g = signal[0], y = signal[1], r = signal[2];
            int x = t % sums[i];
            chk &= (x > g) and (x <= g + y);
        }
        
        if (chk) {
            ans = t;
            break;
        }
    }
    
    return ans;
}