#include <bits/stdc++.h>
using namespace std;

int W, H;
int P, Q;
int T;

int f(int S, int L, int T) {
    T %= L << 1;
    int E = S + T;

    if (E < L) return E;
    E = (L << 1) - E;

    if (E > 0) return E;
    E = -E;

    return E;
}

int main() {
    cin >> W >> H;
    cin >> P >> Q;
    cin >> T;

    int X = f(P, W, T);
    int Y = f(Q, H, T);
    cout << X << ' ' << Y << '\n';
    return 0;
}
