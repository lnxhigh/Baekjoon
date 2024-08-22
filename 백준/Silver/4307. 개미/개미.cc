#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int TC;
const int INF = 10 << 20;

int main() {
    FastIO

    cin >> TC;
    while (TC--) {
        int L, N;
        cin >> L >> N;

        int m = 0, M = 0;
        for (int i = 0; i < N; i++) {
            int X;
            cin >> X;
            m = max(m, min(X, L-X));
            M = max(M, max(X, L-X));
        }

        cout << m << ' ' << M << '\n';
    }

    return 0;
}
