#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int x, y; cin >> x >> y;
        cout << (x / y) << '.';
        x %= y, x *= 10;

        vector<int> rem(y + 1, -1);
        vector<int> decimal(y + 1);

        int cnt = 0;
        int idx = -1;

        while (true) {
            int r = x % y, q = x / y;
            rem[r] = cnt;
            decimal[cnt] = q;
            
            x = r * 10;
            cnt++;

            int nxtr = x % y, nxtq = x / y;

            if (rem[nxtr] >= 0 && decimal[rem[nxtr]] == nxtq) {
                idx = rem[nxtr];
                break;
            }
        }

        for (int i = 0; i < idx; i++) {
            cout << decimal[i];
        }

        cout << '(';
        for (int i = idx; i < cnt; i++) {
            cout << decimal[i];
        }
        
        cout << ')';

        cout << '\n';
    }

    return 0;
}
