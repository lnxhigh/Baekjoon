#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int solve(int64 n) {
    int64 k = 0;
    while (++k) {
        if (k * (1LL << k) - 1 >= n) break;
    }
    return --k;
}

int main() {
    int64 N; cin >> N;
    cout << solve(N);
    return 0;
}
