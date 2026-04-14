#include <bits/stdc++.h>

using namespace std;
using ll = long long;

pair<int,int> f(ll x, const vector<ll> &sum) {
    int idx = upper_bound(sum.begin(), sum.end(), x) - sum.begin() - 1;
    int pos = x - sum[idx];
    return { idx, pos };
}

ll sum(ll x, const vector<int> &arr,
    const vector<ll> &sum1, const vector<ll> &sum2
) {
    if (x < 0) return 0;
    
    auto [idx, pos] = f(x, sum1);
    return sum2[idx] + (ll) arr[idx] * (pos + 1);
}

vector<long long> solution(vector<int> arr, long long l, long long r) {
    int n = arr.size();
    vector<ll> sum1(n), sum2(n);
    l--, r--;
    
    for (int i = 1; i < n; i++) {
        sum1[i] += sum1[i - 1] + arr[i - 1];
        sum2[i] += sum2[i - 1] + (ll) arr[i - 1] * arr[i - 1];
    }
    
    // K
    ll K = sum(r, arr, sum1, sum2) - sum(l - 1, arr, sum1, sum2);
    
    // C
    ll C = 0;
    ll idx = 0;
    ll m = sum1[n - 1] + arr[n - 1];
    
    while (idx + r - l < m) {
        ll x = idx;
        ll y = x + (r - l);
        
        auto [xidx, xpos] = f(x, sum1);
        auto [yidx, ypos] = f(y, sum1);
        
        int cnt = min(arr[xidx] - xpos, arr[yidx] - ypos);
        ll diff = arr[yidx] - arr[xidx];
        
        ll s = sum(y, arr, sum1, sum2) - sum(x - 1, arr, sum1, sum2);
        ll e = s + diff * (cnt - 1);
        
        if (s == K and e == K) C += cnt;
        else if (s <= K and e >= K) C += ((e - K) % abs(diff) == 0);
        else if (s >= K and e <= K) C += ((s - K) % abs(diff) == 0);
        
        idx += cnt;
    }    
    
    return { K, C };
}
