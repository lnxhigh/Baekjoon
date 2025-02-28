#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO
    int T; cin >> T;

    while (T--) {
        int N; cin >> N;
        int K = (0.5 * log(2 * acos(-1) * N) + N * (log(N) - 1)) / log(10);
        cout << ++K << '\n';
    }

    return 0;
}
