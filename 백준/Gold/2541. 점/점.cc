#include <bits/stdc++.h>
using namespace std;

int main() {
    int t = 5;
    int a, b; cin >> a >> b;

    int d = abs(a - b);
    while (d && d % 2 == 0) d /= 2;

    while (t--) {
        int p, q;
        cin >> p >> q;

        bool flag = false;
        if (a > b) flag = (p > q) && ((p - q) % d == 0);
        else if (a < b) flag = (p < q) && ((q - p) % d == 0);
        else flag = (p == q);

        cout << "NY"[flag] << '\n';
    }


    return 0;
}
