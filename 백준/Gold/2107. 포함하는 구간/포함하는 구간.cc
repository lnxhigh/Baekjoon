#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO

    int n; cin >> n;
    vector<pair<int,int>> arr(n);
    for (auto& [x, y] : arr) cin >> x >> y;
    sort(arr.begin(), arr.end());

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = i + 1; j < n; j++) {
            if (arr[i].second > arr[j].second) cnt++;
            else if (arr[i].second < arr[j].first) break;
        }
        ans = max(ans, cnt);
    }

    cout << ans << '\n';
    return 0;
}
