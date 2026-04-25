#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO
    int N; cin >> N;
    int Y = 0, M = 0;
    for (int i = 0; i < N; i++) {
        int X; cin >> X;
        Y += (X / 30 + 1) * 10;
        M += (X / 60 + 1) * 15;
    }

    int m = min(Y, M);
    if (Y < M) cout << "Y " << m << '\n';
    else if (Y > M) cout << "M " << m << '\n';
    else cout << "Y M " << m << '\n';
    return 0;
}
