#include <bits/stdc++.h>
using namespace std;

int main() {
    int  N; cin >> N;
    int two = 0, five = 0;
    for (int i = 1; i <= N; i++) {
        int x = i;
        while (x % 2 == 0 || x % 5 == 0) {
            if (x % 2 == 0) { two++; x /= 2; }
            if (x % 5 == 0) { five++; x /= 5; }
        }
    }

    int res = min(two, five);
    cout << res << '\n';
    return 0;
}
