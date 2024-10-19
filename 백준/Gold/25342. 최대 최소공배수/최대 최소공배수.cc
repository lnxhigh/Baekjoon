#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int64 N, X; cin >> N;
        if      (N % 2) X = N * (N - 1) * (N - 2);
        else if (N % 3) X = N * (N - 1) * (N - 3);
        else            X = (N - 1) * (N - 2) * (N - 3);
        cout << X << '\n';
    }

    return 0;
}
