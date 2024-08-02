#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int ans = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 0; j < (1 << i); j++) {
            int res = 0, mul = 1;
            for (int k = 0; k < i; k++) {
                int x = j & (1 << k) ? 4 : 7;
                res += mul * x;
                mul *= 10;
            }

            if (res <= N) ans = max(ans, res);
        }
    }

    cout << ans << '\n';
    return 0;
}
