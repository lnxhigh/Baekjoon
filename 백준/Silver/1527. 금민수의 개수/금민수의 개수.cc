#include <bits/stdc++.h>
using namespace std;

int A, B;

int main() {
    cin >> A >> B;
    
    int ans = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j < (1 << i); j++) {
            int res = 0, mul = 1;
            for (int k = 0; k < i; k++) {
                int x = j & (1 << k) ? 4 : 7;
                res += mul * x;
                mul *= 10;
            }

            if (A <= res && res <= B) ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
