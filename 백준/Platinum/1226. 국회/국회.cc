#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100'001;

int n;
vector<pair<int,int>> arr;

int sum = 0;
bool dp[MAX];
int now[MAX];
int pre[MAX];

int main() {
    FastIO

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        arr.emplace_back(x, i);
        sum += x;
    }

    sort(arr.rbegin(), arr.rend());

    dp[0] = true;

    for (int i = 0; i < n; i++) {
        auto [x, idx] = arr[i];

        for (int j = sum; j >= x; j--) {
            if (!dp[j] && dp[j - x]) {
                dp[j] = true;
                now[j] = i;
                pre[j] = j - x;
            }
        }
    }

    int m = 0;
    int half = sum / 2;

    for (int x = half + 1; x <= sum; x++) {
        if (!dp[x]) continue;

        int v = arr[now[x]].first;
        if (dp[x] && (x - v <= half)) m = x;
    }

    vector<int> items;

    for (int x = m; x > 0; x = pre[x]) {
        int idx = arr[now[x]].second;
        items.emplace_back(idx);
    }

    cout << items.size() << '\n';
    for (int idx : items) cout << idx + 1 << ' ';
    cout << '\n';

    return 0;
}
