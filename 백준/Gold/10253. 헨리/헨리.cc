#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int Henry(int A, int B) {
    while (A != 1) {
        int X = (B + A - 1) / A;
        A = A * X - B;
        B = B * X;
        
        int D = gcd(A, B);
        A /= D; B /= D;
    }
    return B;
}

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int A, B; cin >> A >> B;
        int X = Henry(A, B);
        cout << X << '\n';
    }
    return 0;
}
