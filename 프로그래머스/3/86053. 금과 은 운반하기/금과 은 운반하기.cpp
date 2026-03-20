#include <bits/stdc++.h>

using namespace std;

bool f(long long t, long long x, long long y, 
    const vector<int> &golds, const vector<int> &silvers, 
    const vector<int> &weights, const vector<int> &times
) {
    int n = times.size();
    long long gold = 0, silver = 0, sum = 0;
    
    // Network flow
    for (int i = 0; i < n; i++) {
        if (t < times[i]) continue;
        long long cnt = (t - times[i]) / (times[i] * 2) + 1;
        
        long long gi = golds[i];
        long long si = silvers[i];
        long long wi = cnt * weights[i];
        
        gold += min(gi, wi);
        silver += min(si, wi);
        sum += min(gi + si, wi);
    }
    
    return gold >= x and silver >= y and sum >= x + y;
}

long long solution(int x, int y, 
    vector<int> golds, vector<int> silvers, 
    vector<int> weights, vector<int> times
) {
    long long t = -1;
    long long low = 0, high = 1e15;
    
    while (low <= high) {
        long long mid = (low + high) / 2;
        bool chk = f(mid, x, y, golds, silvers, weights, times);
        if (chk) t = mid, high = mid - 1;
        else low = mid + 1;
    }
    
    return t;
}