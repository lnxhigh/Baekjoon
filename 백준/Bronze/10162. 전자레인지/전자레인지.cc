#include <bits/stdc++.h>
using namespace std;

int T;
int buttons[3] = { 5*60, 1*60, 10 };
int cnt[3];

int main() {
    cin >> T;
    for (int i = 0; i < 3; i++) {
        int k = buttons[i];
        cnt[i] = T / k;
        T %= k;
    }

    if (T > 0) cout << -1;
    else for (int i = 0; i < 3; i++) cout << cnt[i] << ' ';
    cout << '\n';
    return 0;
}
