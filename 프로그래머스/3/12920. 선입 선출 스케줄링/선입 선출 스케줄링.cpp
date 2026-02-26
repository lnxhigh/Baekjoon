#include <bits/stdc++.h>
using namespace std;

long long f(int t, const vector<int> &cores) {
    long long sum = cores.size();
    for (int x : cores) sum += (t / x);
    return sum;
}

int solution(int n, vector<int> cores) {
    int low = 1;
    int high = 10000 * 50000;
    
    int t = 0;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (f(mid, cores) < n) t = mid, low = mid + 1;
        else high = mid - 1;
    }
    
    int ans = -1;
    int cnt = n - f(t, cores);
    
    for (int i = 0; i < cores.size() && cnt > 0; i++) {
        if ((t + 1) % cores[i] == 0) cnt--;
        if (cnt == 0) ans = i;
    }

    return ++ans;
}
