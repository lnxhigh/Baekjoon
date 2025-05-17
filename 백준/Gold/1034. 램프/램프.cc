#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = unsigned long long;

int n, m, k;
vector<string> arr;

int ans = 0;
map<ll,int> cache;

int main() {
	FastIO
    
    cin >> n >> m;
    arr.resize(n);
    for (string& str : arr) cin >> str;
    cin >> k;
    
    for (string& str : arr) {
        ll x = stoull(str, nullptr, 2);
        int cnt = m - __builtin_popcountll(x);

        if (cnt > k || cnt % 2 != k % 2) continue;
        ans = max(ans, ++cache[x]);
    }

    cout << ans << '\n';
    return 0;
}
