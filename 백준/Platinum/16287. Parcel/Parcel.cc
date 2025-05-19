#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 5000;

int n, w;
int arr[MAX];
bool dp[1 << 20];

bool solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i - 1; j++) {
            dp[arr[j] + arr[i - 1]] = true;
        }
        for (int j = i + 1; j < n; j++) {
            int x = w - arr[i] - arr[j];
            if (x >= 0 && dp[x]) return true;
        }
    }

    return false;
}

int main() {
    FastIO
    
    cin >> w >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    string ans = solve() ? "YES" : "NO";
    cout << ans << '\n';
    
    return 0;
}
