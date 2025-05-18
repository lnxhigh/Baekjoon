#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int n;
int arr[16];

double dp[1 << 16];
bool vis[1 << 16];

bool check(int x, int y, int z) {
    int a = arr[x], b = arr[y], c = arr[z];
    return a + b > c && b + c > a && c + a > b;
}

double area(int x, int y, int z) {
    double a = arr[x], b = arr[y], c = arr[z];
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double dfs(int x) {
    if (vis[x]) return dp[x];

    double ret = 0;

    for (int i = 0; i < n - 2; i++) {
        if (x >> i & 1) continue;

        for (int j = i + 1; j < n - 1; j++) {
            if (x >> j & 1) continue;

            for (int k = j + 1; k < n; k++) {
                if (x >> k & 1) continue;
                if (!check(i, j, k)) continue;

                int nxt = x + (1 << i) + (1 << j) + (1 << k);
                ret = max(ret, dfs(nxt) + area(i, j, k));
            }
        }
    }
    
    dp[x] = ret;
    vis[x] = true;
    return ret;
}

int main() {
    FastIO

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    double ans = dfs(0);
    cout << setprecision(16);
    cout << ans << '\n';

    return 0;
}
