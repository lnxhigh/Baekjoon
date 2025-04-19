#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO

    int n; cin >> n;
    vector<pair<int,int>> interval(n);
    for (auto& [x, y] : interval) cin >> x >> y;

    vector<int> vec(n);

    // Naive O(n^2)

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            const auto& [a, b] = interval[i];
            const auto& [c, d] = interval[j];

            if (a < c && b > d) vec[i]++;
            else if (c < a && d > b) vec[j]++;
        }
    }

    int ans = *max_element(vec.begin(), vec.end());
    cout << ans << '\n';

    return 0;
}
