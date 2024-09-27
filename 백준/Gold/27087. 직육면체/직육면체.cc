#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int A, B, C; cin >> A >> B >> C;
        int p; cin >> p;

        int cnt = 0;
        for (int x : { A, B, C }) {
            if (x % p == 0) cnt++;
        }

        bool res = (cnt > 1);
        cout << res << '\n';
    }
    
    return 0;
}
