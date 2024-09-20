#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int MOD = 1000000;
const int64 MOD64 = 1000000;

int main() {
    int N; cin >> N;
    int X = 0;
    for (int i = 1; i <= N; i++) {
        X += i * (N / i);
        X %= MOD;
    }

    int64 N64 = N, X64 = X + 1;
    X64 -= N64 + N64 * (N64 + 1) / 2;
    X64 %= MOD64;
    if (X64 < 0) X64 += MOD64;

    cout << X64 << '\n';
    return 0;
}
