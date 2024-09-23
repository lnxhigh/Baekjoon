#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    cout << setprecision(16);

    // Coupon collector's problem
    double H = 0;
    for (int i = 1; i <= N; i++) H += 1.0 / i;
    cout << N * H << '\n';
    return 0;
}
