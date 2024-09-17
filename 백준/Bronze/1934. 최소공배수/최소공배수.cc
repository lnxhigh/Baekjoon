#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int A, B; cin >> A >> B;
        // Does it work?
        cout << lcm(A, B) << '\n';
    }
    return 0;
}
