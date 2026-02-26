#include <bits/stdc++.h>

using namespace std;

long long f(long long t, vector<int> times) {
    long long sum = 0;
    for (int time : times) {
        sum += t / time;
    }
    return sum;
}

long long solution(int n, vector<int> times) {
    long long ans = 0;
    long long low = 1;
    long long high = 1000000000LL * 1000000000LL;
    
    while (low <= high) {
        long long mid = low + high >> 1;
        if (f(mid, times) >= n) ans = mid, high = mid - 1;
        else low = mid + 1;
    }
    
    return ans;
}
