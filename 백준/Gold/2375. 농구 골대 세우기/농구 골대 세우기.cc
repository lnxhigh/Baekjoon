#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

ll n;
vector<pair<ll,ll>> arrX, arrY;
ll sum = 0;

ll f(vector<pair<ll,ll>> &arr) {
    int idx = -1, cnt = 0;
    ll mid = (sum >> 1) + (sum & 1);
    sort(arr.begin(), arr.end());

    while (idx + 1 < n && cnt + arr[idx + 1].second < mid) cnt += arr[++idx].second;
    return arr[++idx].first;
}

int main() {
    FastIO

    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x, y, p; cin >> x >> y >> p;
        sum += p;
        arrX.emplace_back(x, p);
        arrY.emplace_back(y, p);
    }

    cout << f(arrX) << ' ' << f(arrY) << '\n';
    return 0;
}
