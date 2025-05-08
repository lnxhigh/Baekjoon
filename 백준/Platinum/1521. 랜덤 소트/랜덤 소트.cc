#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int n;
vector<int> arr;
map<vector<int>,double> dp;
map<vector<int>,bool> vis;

double dfs(vector<int> &vec) {
    if (vis[vec]) return dp[vec];

    double p = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vec[i] > vec[j]) {
                cnt++;

                swap(vec[i], vec[j]);
                p += dfs(vec);
                swap(vec[i], vec[j]);
            }
        }
    }

    vis[vec] = true;
    return dp[vec] = cnt ? (p / cnt) + 1 : 0;
}

int main() {
    FastIO

    cin >> n;
    arr.resize(n);
    for (int& x : arr) cin >> x, x--;

    cout.precision(16);
    double ans = dfs(arr);
    cout << ans << '\n';

    return 0;
}
