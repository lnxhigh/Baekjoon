#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int TC;

void solve(int R, int C) {
    cout << 1 << '\n';

    for (int r = 0; r < R; r++) {
        cout << '(' << r << ',' << 0 << ')' << '\n';
    }

    for (int r = R-1; r >= 0; r--) {
        int d = R - r;
        int S = (d % 2) ? 1 : C-1;
        int k = (d % 2) ? 1 : -1;

        for (int c = S; c >= 1 && c < C; c += k) {
            cout << '(' << r << ',' << c << ')' << '\n';
        }
    }
}

int main() {
    FastIO

    cin >> TC;
    while (TC--) {
        int R, C;
        cin >> R >> C;
        solve(R, C);
    }
    return 0;
}
