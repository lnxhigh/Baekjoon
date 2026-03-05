#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll f(int x, const vector<vector<int>> &land, ll P, ll Q) {
    ll sum = 0;
    for (const vector<int> &row : land) 
        for (int h : row) 
            sum += P * max(x - h, 0) + Q * max(h - x, 0);
    
    return sum;
}

ll solution(vector<vector<int>> land, int P, int Q) {
    ll low = 0, high = 1000000000;
    
    while (high - low >= 3) {
        ll m1 = (low * 2 + high) / 3;
        ll m2 = (low + high * 2) / 3;
        
        ll x = f(m1, land, P, Q);
        ll y = f(m2, land, P, Q);
    
        if (x <= y) high = m2;
        else low = m1;
    }
    
    ll ans = f(high, land, P, Q);
    for (ll x = low; x < high; x++) {
        ans = min(ans, f(x, land, P, Q));
    }
    
    return ans;
}
