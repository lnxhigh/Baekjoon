#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 300;

int n;
vector<pair<int,int>> arr;

int sum = 0;
bitset<100001> dp[MAX];

int main() {
    FastIO

    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        arr[i] = { x, i + 1 };
        sum += x;
    }

    sort(arr.rbegin(), arr.rend());

    dp[0][0] = 1;
    dp[0][arr[0].first] = 1;

    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1];
        int x = arr[i].first;
        int m = min(sum / 2, 100000 - x);
        for (int j = 0; j <= m; j++) {
            dp[i][j + x] = dp[i][j + x] | dp[i - 1][j];
        }
    }

    int m = 0;
    for (int i = 0; i <= 100000; i++) {
        if (dp[n - 1][i]) m = i;
    }

    vector<int> items;
    
    for (int i = n - 1; i > 0; i--) {
        auto [x, idx] = arr[i];
        if ((!dp[i - 1][m]) && m >= x && dp[i - 1][m - x]) {
            items.push_back(idx);
            m -= x;
        }
    }

    if (m > 0) items.push_back(arr[0].second);

    sort(items.begin(), items.end());
    cout << items.size() << '\n';
    for (int x : items) cout << x << ' ';
    cout << '\n';

    return 0;
}
