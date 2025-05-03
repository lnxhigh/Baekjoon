#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const int MAX = 10001;

ll n, m;
ll arr[MAX];

int main() {
    FastIO

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    ll t = 0, s = 0;
    ll lo = 0, hi = n * 30;

    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        
        ll sum = 0;
        for (int i = 0; i < m; i++) {
            ll cnt = mid / arr[i];
            if (mid % arr[i]) cnt++;
            sum += cnt;
        }

        if (sum < n) t = mid, s = sum, lo = mid + 1;
        else hi = mid - 1;
    }
    
    vector<int> vec;
    for (int i = 0; i < m; i++) {
        if (t % arr[i] == 0) vec.push_back(i);
    }

    int ans = vec[n - s - 1];
    cout << ans + 1 << '\n';

    return 0;
}
