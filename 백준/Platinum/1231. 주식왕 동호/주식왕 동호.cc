#include <bits/stdc++.h>
using namespace std;

int c, d, m;
int arr[50][10];

int main() {
    cin >> c >> d >> m;

    for (int i = 0; i < c; i++) {
        for (int day = 0; day < d; day++) {
            cin >> arr[i][day];
        }
    }

    for (int day = 0; day + 1 < d; day++) {
        vector<int> dp(m + 1);

        for (int i = 0; i < c; i++) {
            int v = arr[i][day + 1] - arr[i][day];
            if (v <= 0) continue;
            
            int p = arr[i][day];
            for (int w = p; w <= m; w++) {
                dp[w] = max(dp[w], dp[w - p] + v);
            }
        }
        
        m += dp[m];
    }

    cout << m << '\n';
    return 0;
}
