#include <bits/stdc++.h>
using namespace std;

int X[6] = { 13, 7, 5, 3, 3, 2 };

int main() {
    double cocjr0208 = 0.0;
    double ekwoo = 1.5;

    for (int i = 0; i < 6; i++) {
        int cnt; cin >> cnt;
        cocjr0208 += X[i] * cnt;
    }
    for (int i = 0; i < 6; i++) {
        int cnt; cin >> cnt;
        ekwoo += X[i] * cnt;
    }

    if (cocjr0208 > ekwoo) cout << "cocjr0208";
    else cout << "ekwoo";
    cout << '\n';
    return 0;
}
