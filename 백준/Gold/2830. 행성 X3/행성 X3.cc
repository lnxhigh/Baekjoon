#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO
    
    int n; cin >> n;
    vector<int> arr(n);
    for (int& x : arr) cin >> x;

    long long ans = 0;
    for (int i = 0; i < 20; i++) {
        int t[2] = { 0, 0 };
        for (const int& x : arr) {
            t[x >> i & 1]++;
        }
        ans += (long long) t[0] * t[1] * (1 << i);
    }

    cout << ans;
    return 0;
}
