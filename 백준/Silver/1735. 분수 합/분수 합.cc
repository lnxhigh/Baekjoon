#include <bits/stdc++.h>
using namespace std;

int A, B, C, D;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin >> A >> B;
    cin >> C >> D;

    int p = A * D + B * C;
    int q = B * D;
    
    int d = gcd(p, q);
    p /= d; q /= d;

    cout << p << ' ' << q << '\n';
    return 0;
}
