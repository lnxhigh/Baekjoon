#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    int64 X, Y, K;
    Y = 0; cin >> X >> K;

    for (int i = 0, j = 0; i < 64; i++) {
        if (X >> i & 1) continue;
        if (K >> j++ & 1) Y += 1LL << i;
    }
    
    cout << Y << '\n';
    return 0;
}
